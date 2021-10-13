/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/10/12 13:55:18 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_child(t_cmd *cmd, char *binary, char **args)
{
	if (ft_strcmp(binary, "echo") == 0)
		echo_builtin(cmd->args, cmd->out);
	else if (ft_strcmp(binary, "env") == 0)
		env_builtin(cmd->out);
	else if (ft_strcmp(binary, "pwd") == 0)
		pwd_builtin(cmd);
	else
	{
		if (cmd->out)
		{
			dup2(cmd->out, 1);
			close(cmd->out);
		}
		if (cmd->in)
		{
			dup2(cmd->in, 0);
			close(cmd->in);
		}
		execve(binary, args, NULL);
	}
	ft_free_tab(args);
	free_all();
	exit(EXIT_SUCCESS);
}

static void	exec_command(t_cmd *cmd, char *binary)
{
	char	**args;
	int		status;

	args = list_to_tab(cmd);
	g_ms->pid = fork();
	if (g_ms->pid < 0)
		error("error forking", NULL, NULL, -1);
	else if (g_ms->pid == 0)
		exec_child(cmd, binary, args);
	else
	{
		waitpid(g_ms->pid, &status, 0);
		status_child(status);
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
		if (is_builtin(cmd->cmd))
			exec_command(cmd, cmd->cmd);
		else
		{
			bin = find_binary(cmd, 1);
			if (bin)
				exec_command(cmd, bin);
			free(bin);
		}
	}
	g_ms->fork = 0;
	return (0);
}

static void	exec_switch(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "cd") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		cd_builtin(cmd);
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
		if (edit_args(cmd))
		{
			redirect(cmd);
			if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
				exec_switch(cmd);
			if (cmd->in)
				close(cmd->in);
			if (cmd->out)
				close(cmd->out);
		}
		cmd = cmd->next;
	}
}
