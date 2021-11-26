/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/11/12 15:47:09 by jode-vri         ###   ########.fr       */
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

t_token	*lstcreate(char *data, t_token *next)
{
	t_token	*cell;

	cell = malloc(sizeof(t_token));
	if (cell == NULL)
		return (NULL);
	cell->word = ft_strdup(data);
	cell->type = 5;
	cell->next = next;
	return (cell);
}

void test(t_cmd *cmd)
{
	char	**res;
	t_token	*tmp;
	t_token *tmp2;
	int		i;

	if (is_in_str(cmd->cmd, ' '))
	{
		i = 0;
		res = ft_split(cmd->cmd, " ");
		free(cmd->cmd);
		cmd->cmd = ft_strdup(res[0]);
		tmp = cmd->args->next;
		while (cmd->args)
		{
			tmp2 = cmd->args->next;
			free(cmd->args->word);
			free(cmd->args);
			cmd->args = tmp2;
		}
		cmd->args = lstcreate(res[1], tmp);
		free(cmd->bin);
		free(cmd->cmd);
		cmd->cmd = ft_strdup(res[0]);
		ft_free_tab(res);
	}
	g_ms->double_chk = 1;
}

void	exec_start(void)
{
	t_cmd	*cmd;
	int		pipe1[2];

	cmd = g_ms->cmds;
	while (cmd)
	{
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
