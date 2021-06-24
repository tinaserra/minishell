/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/24 14:49:55 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		echo_builtin(cmd->args, cmd->out);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		env_builtin(cmd->out);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		cd_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd_builtin();
	else
		start_command(cmd);
}

void	exec_cmds(void)
{
	t_cmd	*cmd;

	cmd = g_ms->cmds;
	while (cmd)
	{
		//edit_args(cmd);
		redirect(cmd);
		exec_cmd(cmd);
		if (cmd->in)
			close(cmd->in);
		if (cmd->out)
			close(cmd->out);
		cmd = cmd->next;
	}
}

void	free_commands(void)
{
	t_cmd	*tmp;
	t_token	*tmp2;

	while (g_ms->cmds)
	{
		while (g_ms->cmds->args)
		{
			tmp2 = g_ms->cmds->args->next;
			free(g_ms->cmds->args->word);
			free(g_ms->cmds->args);
			g_ms->cmds->args = tmp2;
		}
		tmp = g_ms->cmds->next;
		free(g_ms->cmds->cmd);
		free(g_ms->cmds);
		g_ms->cmds = tmp;
	}
}
