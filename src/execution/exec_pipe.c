/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:19 by vserra            #+#    #+#             */
/*   Updated: 2021/10/20 10:31:32 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define READ 0
#define WRITE 1

void	handle_fds(t_cmd *cmd, int fdd, int fd[2])
{
	dup2(fdd, 0);
	if (cmd->next)
		dup2(fd[WRITE], 1);
	if (cmd->out > 0)
	{
		dup2(cmd->out, 1);
		close(cmd->out);
	}
	if (cmd->in > 0)
	{
		dup2(cmd->in, 0);
		close(cmd->in);
	}
}

void	builtin_pipe(t_cmd *cmd, char *bin, char **args)
{
	if (ft_strcmp(cmd->cmd, "env") == 0)
		env_builtin(0);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		echo_builtin(cmd, 0);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd_builtin(cmd);
	else
		execve(bin, args, NULL);
}

void	exec_pipe(t_cmd *cmd)
{
	int		fd[2];
	int		fdd;
	char	**args;
	char	*bin;
	int		status;

	fdd = 0;
	status = 0;
	while (cmd && (cmd->type == PIPE || (cmd->prev && cmd->prev->type == PIPE)))
	{
		redirect(cmd);
		bin = find_binary(cmd, 0);
		args = list_to_tab(cmd);
		pipe(fd);
		g_ms->pid = fork();
		if (g_ms->pid == -1)
		{
			error("error forking", NULL, NULL, -1);
			exit(EXIT_SUCCESS);
		}
		else if (g_ms->pid == 0)
		{
			handle_fds(cmd, fdd, fd);
			builtin_pipe(cmd, bin, args);
			close(fd[READ]);
			ft_free_tab(args);
			free(bin);
			free_all();
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(g_ms->pid, &status, 0);
			status_child(status);
			close(fd[WRITE]);
			fdd = fd[READ];
			free(bin);
			cmd = cmd->next;
		}
		ft_free_tab(args);
	}
}
