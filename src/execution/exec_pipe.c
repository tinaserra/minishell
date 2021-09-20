/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:46:46 by vserra            #+#    #+#             */
/*   Updated: 2021/09/20 09:11:45 by jode-vri         ###   ########.fr       */
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

		//printf("%s\n", cmd->cmd);
	fdd = 0;
	while (cmd && (cmd->type == PIPE || (cmd->prev && cmd->prev->type == PIPE)))
	{
		args = list_to_tab(cmd);
		pipe(fd); // ERR
		pid = fork();
		if (pid == -1)
		{
			print_error(FORK); // ERR
			exit(1);
		}
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (cmd->next)
				dup2(fd[1], 1);
			close(fd[0]);
			execve(cmd->cmd, args, NULL);
			exit(1);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fdd = fd[0];
			free(args);
			cmd = cmd->next;
		}
	}	
}
