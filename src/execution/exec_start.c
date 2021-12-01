/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/12/01 15:39:50 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_binary2(t_cmd *cmd, pid_t pid, int pipe1[2])
{
	int	status;
	int	pipe2[2];

	if (pipe(pipe2) < 0)
		return ;
	if (cmd->type == PIPE)
	{
		edit_args(cmd->next);
		redirect(cmd->next);
		while (cmd->next && !cmd->next->cmd)
		{
			edit_args(cmd);
			redirect(cmd);
			cmd = cmd->next;
		}
		if (cmd->next)
			exec_binary(cmd->next, pipe1, pipe2);
	}
	close_all(pipe1, pipe2);
	waitpid(pid, &status, WUNTRACED);
	status_child(cmd, status);
}

void	exec_bin_check(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "") == 0)
		error("command not found", cmd->cmd, NULL, 127);
	else
	{
		if (!is_builtin(cmd->cmd))
			g_ms->fork = 1;
		cmd->bin = find_binary(cmd, 1);
		cmd->argss = list_to_tab(cmd);
	}
}

void	exec_binary(t_cmd *cmd, int pipe1[2], int pipe2[2])
{
	exec_bin_check(cmd);
	g_ms->pid = fork();
	if (g_ms->pid < 0)
		error("error forking", NULL, NULL, -1);
	else if (g_ms->pid == 0)
	{
		if (cmd->in == -1 || cmd->out == -1)
			exit(1);
		handle_fds(cmd, pipe1, pipe2);
		execute(cmd);
		close(cmd->in);
		close(cmd->out);
	}
	else
	{
		if (cmd->type == PIPE && cmd->prev && cmd->prev->type == PIPE
			&& !close(pipe1[1]) && !close(pipe1[0]))
			exec_binary2(cmd, g_ms->pid, pipe2);
		else
			exec_binary2(cmd, g_ms->pid, pipe1);
	}
}

static void	exec_switch(t_cmd *cmd, int pipe1[2])
{
	if (ft_strcmp(cmd->cmd, "cd") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		cd_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "export") == 0 && cmd->args)
		export_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		unset_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "exit") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		exit_builtin(cmd);
	else if (!cmd->prev || (cmd->prev && cmd->prev->type != PIPE))
		exec_binary(cmd, pipe1, NULL);
}

void	exec_start(void)
{
	t_cmd	*cmd;
	int		pipe1[2];

	cmd = g_ms->cmds;
	while (cmd)
	{
		g_ms->unclosed = 0;
		test(cmd);
		edit_args(cmd);
		redirect(cmd);
		if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
		{
			if (pipe(pipe1))
				return ;
			exec_switch(cmd, pipe1);
			close(pipe1[0]);
			close(pipe1[1]);
		}
		while (cmd->type == PIPE)
			cmd = cmd->next;
		cmd = cmd->next;
	}
}
