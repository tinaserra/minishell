/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:04:15 by vserra            #+#    #+#             */
/*   Updated: 2021/09/15 08:42:12 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define READ 0 // stdin
#define WRITE 1 // stdout

static void	pipeline(char ***cmd, char **env)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;

	while (*cmd != NULL)
	{
		/* create the pipe */
		if (pipe(fd) == -1)
			print_error("pipe failled\n");

		/* create the child */
		pid = fork();
		if (pid < 0)
			print_error("fork failled\n");

		/* child process */
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL) {
				dup2(fd[WRITE], 1);
			}
			close(fd[READ]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}

		/* parent process */
		else
		{
			wait(NULL);			/* Collect childs */
			close(fd[WRITE]);
			fdd = fd[READ];
			cmd++;
		}
	}
}

int		main(int argc, char *argv[], char **env)
{
	char *ls[] = {argv[1], argv[2], NULL};
	char *rev[] = {"rev", NULL};
	char *nl[] = {"nl", NULL};
	char *cat[] = {argv[3], NULL};
	char **cmd[] = {ls, cat, NULL};

	//printf("%s\n",env[0]);

	pipeline(cmd, env);
	return (0);
}
