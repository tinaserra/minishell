/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:21:13 by admin             #+#    #+#             */
/*   Updated: 2021/11/11 15:22:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_fds(t_cmd *cmd, int pipe1[2], int pipe2[2])
{
	if (cmd->prev && cmd->prev->type == PIPE)
	{
		dup2(pipe1[0], 0);
		close(pipe1[1]);
		if (cmd->type == PIPE)
		{
			dup2(pipe2[1], 1);
			close(pipe2[0]);
		}
	}
	else if (cmd->type == PIPE)
	{
		dup2(pipe1[1], 1);
		close(pipe1[0]);
	}
	if (cmd->out > 0)
		dup2(cmd->out, 1);
	if (cmd->in > 0)
		dup2(cmd->in, 0);
}

void	close_all(int pipe1[2], int pipe2[2])
{
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
}

void	status_child(int status)
{
	if (WIFEXITED(status))
		g_ms->status = WEXITSTATUS(status);
	if (WIFSIGNALED(g_ms->pid))
	{
		g_ms->status = WTERMSIG(g_ms->pid);
		if (g_ms->status != 131)
			g_ms->status += 128;
	}
}
