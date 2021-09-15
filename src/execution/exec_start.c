/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/15 11:53:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(char *binary, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_error("Error Forking\n");
	else if (pid == 0)		/* child process */
	{
		execve(binary, args, NULL);
		exit(1);
	}
	else					/* parent process */
		wait(NULL);
}

int	exec_binary(t_cmd *cmd) // start_command -> EXEC_BINARY
{
	char	*binary;
	char	*binary2;
	char	**args;
	char	**args2;

	args = list_to_tab(cmd);
	binary = check_path(cmd);
	if (cmd->type == PIPE)
	{
		binary2 = check_path(cmd->next);
		args2 = list_to_tab(cmd->next);
		if (binary)
			exec_pipe(binary, binary2, args, args2);
		else
			exec_pipe(cmd->cmd, cmd->next->cmd, args, args2);
	}
	else
	{
		if (binary)
			exec_command(binary, args);
		else
			exec_command(cmd->cmd, args);
	}
	return (0);
}

void	exec_switch(t_cmd *cmd) //exec_cmd -> EXEC_SWITCH
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

void	exec_start(void) // exec_cmds -> EXEC_START
{
	t_cmd	*cmd;

	cmd = g_ms->cmds;
	while (cmd)
	{
		edit_args(cmd);
		redirect(cmd);
		if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
			exec_switch(cmd); //exec_cmd -> EXEC_SWITCH
		if (cmd->in)
			close(cmd->in);
		if (cmd->out)
			close(cmd->out);
		cmd = cmd->next;
	}
}
