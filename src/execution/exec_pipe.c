/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:46:46 by vserra            #+#    #+#             */
/*   Updated: 2021/09/21 14:46:15 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define READ 0		/* stdin */
#define WRITE 1		/* stdout */

void	exec_pipe(t_cmd *cmd) // EXEC_PIPE
{
	int		fd[2];
	pid_t	pid;
	int		fdd;
	char	**args;
	char	*bin;

	fdd = 0;
	while (cmd && (cmd->type == PIPE || (cmd->prev && cmd->prev->type == PIPE)))
	{
		bin = find_binary(cmd, 0);
		args = list_to_tab(cmd);
		pipe(fd);
		pid = fork();
		if (pid == -1)
		{
			print_error(FORKING, NULL, NULL);
			exit(EXIT_SUCCESS);
		}
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (cmd->next)
				dup2(fd[1], 1);
			close(fd[0]);
			execve(bin, args, NULL);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			// g_ms->erno = errno;
			close(fd[1]);
			fdd = fd[0];
			ft_free_tab(args);
			free(bin);
			cmd = cmd->next;
		}
	}	
}
