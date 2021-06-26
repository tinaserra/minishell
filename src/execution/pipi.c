/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:46:46 by vserra            #+#    #+#             */
/*   Updated: 2021/06/26 16:54:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define READ 0 // stdin
#define WRITE 1 // stdout

int	create_pipe(t_cmd *cmd)
{
	int		fd[2];

	int		pid;
	//char	buffer[BUFSIZ];
	char	**args;
	char	**args2;

	args = list_to_tab(cmd);
	args2 = list_to_tab(cmd->next);

	/* create the pipe */
	if (pipe(fd) == -1)
		print_error("pipe failled\n");

	/* create the child */
	pid = fork();
	if (pid < 0)
		print_error("fork failled\n");

	/* child process */
	if (pid == 0)
	{
		close(fd[WRITE]);
		dup2(fd[READ], 0); /* connect the read side with stdin */
		close(fd[READ]);

		/* execute the process (command 2) */
		execve(cmd->next->cmd, args2, NULL);

		/* read some data and print the result on screen */
		// while (read(fd[READ], buffer, BUFSIZ) != 0)
		// printf("child reads %s", buffer);
	}
	/* parent process */
	else
	{
		close(fd[READ]);
		dup2(fd[WRITE], 1); /* connect the write side with stdout */
		close(fd[WRITE]);

		/* execute the process (command 1) */
		execve(cmd->cmd, args, NULL);

		// write(fd[WRITE], buffer, strlen(buffer)+1);
	}
	return (0);
}