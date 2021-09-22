/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/22 20:11:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_command(t_cmd *cmd, char *binary)
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

static int	exec_binary(t_cmd *cmd)
{
	char	*bin;

	g_ms->fork = 1;
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
	g_ms->fork = 0;
	return (0);
}

static void	exec_switch(t_cmd *cmd)
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
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		exit_builtin(cmd);
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
