/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/20 09:30:13 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(char *binary, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_error(1);
	else if (pid == 0)		/* child process */
	{
		execve(binary, args, NULL);
		exit(1);
	}
	else					/* parent process */
		wait(NULL);
}

int	exec_binary(t_cmd *cmd)
{
	char	*binary;
	char	**args;
	//t_cmd	*tmp;
	struct stat stats;

	if (cmd->type == PIPE)
	{
		binary = check_path(cmd);
		if (binary)
		{
			free(cmd->cmd);
			cmd->cmd = ft_strdup(binary);
			exec_pipe(cmd);
		}
		else
		{
			if (lstat(cmd->cmd, &stats))
				printf("minishell: %s: command not found\n", cmd->cmd); // ERR
			else
				exec_pipe(cmd);
		}
		free(binary);
	}
	else
	{
		binary = check_path(cmd);
		args = list_to_tab(cmd);
		printf("%s\n", args[0]);
		if (binary)
			exec_command(binary, args);
		else
		{
			printf("abc\n");
			if (lstat(cmd->cmd, &stats))
				printf("minishell: %s: command not found\n", cmd->cmd); // ERR
			else
				exec_command(cmd->cmd, args);
		}
		free(binary);
		ft_free_tab(args);
	}
	return (0);
}

void	exec_switch(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		echo_builtin(cmd->args, cmd->out);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		env_builtin(cmd->out);
	else if (ft_strcmp(cmd->cmd, "cd") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		cd_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd_builtin();
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		export_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		unset_builtin(cmd);
	else if (!cmd->prev || (cmd->prev && cmd->prev->type != PIPE))
		exec_binary(cmd);
}

void	exec_start(void)
{
	t_cmd	*cmd;

	cmd = g_ms->cmds;
	while (cmd)
	{
		edit_args(cmd);
		redirect(cmd);
		if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
			exec_switch(cmd);
		if (cmd->in)
			close(cmd->in);
		if (cmd->out)
			close(cmd->out);
		cmd = cmd->next;
	}
}
