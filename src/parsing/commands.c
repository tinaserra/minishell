/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/09/08 15:04:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_cmd *cmd, int fd[2])
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
	else if (!cmd->prev || (cmd->prev && cmd->prev->type != PIPE))
		start_command(cmd, fd);
}

void	edit_args(t_cmd *cmd)
{
	t_token	*tmp;
	//int		is_env;

	tmp = cmd->args;
	while (tmp)
	{
		//is_env = 0;
		/*if (tmp->word && tmp->word[0] == '$')
			is_env = 1;*/
		tmp->word = handle_quotes(tmp->word, 1);
		tmp = tmp->next;
	}
}

void	exec_cmds(void)
{
	t_cmd	*cmd;
	int		fd[2];

	cmd = g_ms->cmds;
	while (cmd)
	{
		edit_args(cmd);
		redirect(cmd);
		if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
		{
			/* create the pipe */
			if (pipe(fd) == -1)
				print_error("pipe failled\n");
			//printf("%d\n", cmd->type);
			exec_cmd(cmd, fd);

		}
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
