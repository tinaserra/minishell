/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/11/08 09:37:39 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_fds(t_cmd *cmd, int pipe1[2], int pipe2[2])
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

static void execute(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->cmd, "echo"))
		echo_builtin(cmd, cmd->out);
	else if (!ft_strcmp(cmd->cmd, "env"))
		env_builtin(cmd->out);
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		pwd_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "cd"))
		cd_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "exit"))
		exit_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "export"))
		export_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "unset"))
		exit(0);
	else if (cmd->cmd && g_ms->env && cmd->argss)
	{
		if (cmd->bin)
			execve(cmd->bin, cmd->argss, NULL);
		else
			error("command not found", cmd->cmd, NULL, 127);
		free_all();
		exit(0);
	}
	free_all();
	exit(0);
}

static void exec_binary2(t_cmd *cmd, pid_t pid, int pipe1[2])
{
	int status;
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
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	waitpid(pid, &status, WUNTRACED);
	while (!WIFEXITED(status))
		if (!WIFSIGNALED(status) || g_ms->end != 0 || cmd->type == PIPE)
			break ;
	if (WIFEXITED(status) && cmd->type != PIPE)
		g_ms->exit = WEXITSTATUS(status);
}

void exec_binary(t_cmd *cmd, int pipe1[2], int pipe2[2])
{
	pid_t	pid;

	if (!is_builtin(cmd->cmd))
		g_ms->fork = 1;
	cmd->bin = find_binary(cmd, 1);
	cmd->argss = list_to_tab(cmd);
	pid = fork();
	if (pid < 0)
		error("error forking", NULL, NULL, -1);
	else if (pid == 0)
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
			exec_binary2(cmd, pid, pipe2);
		else
			exec_binary2(cmd, pid, pipe1);
	}
	//ft_free_tab(cmd->argss);
	//g_ms->fork = 0;
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
