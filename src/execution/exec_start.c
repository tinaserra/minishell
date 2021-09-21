/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/21 14:58:16 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_cmd *cmd, char *binary)
{
	char	**args;

	args = list_to_tab(cmd);
	g_ms->pid = fork();
	if (g_ms->pid < 0)
		print_error(FORKING, NULL, NULL);
	else if (g_ms->pid == 0)		/* child process */
	{
		dup2(cmd->out, 1);
		execve(binary, args, NULL);
		exit(EXIT_SUCCESS);
	}
	else					/* parent process */
	{
		wait(&g_ms->pid);
		status_child();
		ft_free_tab(args);
	}
}

char	*find_binary(t_cmd *cmd, int show)
{
	struct stat stats;
	char		*binary;

	binary = check_path(cmd);
	if (!binary)
	{
		if (lstat(cmd->cmd, &stats))
		{
			if (show)
				print_error(CMD, cmd->cmd, NULL);
			free(binary);
			return (NULL);
		}
		free(binary);
		binary = ft_strdup(cmd->cmd);
	}
	return (binary);
}

int	find_all_binary(t_cmd *cmd)
{
	t_cmd	*tmpp;
	char	*bin;

	tmpp = cmd;
	while (tmpp)
	{
		bin = find_binary(tmpp, 1);
		if (!bin)
		{
			free(bin);
			return (0);
		}
		free(bin);
		tmpp = tmpp->next;
	}
	return (1);	
}

int	exec_binary(t_cmd *cmd)
{
	char	*bin;

	if (cmd->type == PIPE)
	{
		if (!find_all_binary(cmd))
			return (0);
		exec_pipe(cmd);
	}
	else
	{
		bin = find_binary(cmd, 1);
		exec_command(cmd, bin);
		free(bin);
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
		pwd_builtin(cmd);
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
