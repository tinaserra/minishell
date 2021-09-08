/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/08 15:30:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define READ 0 // stdin
#define WRITE 1 // stdout

int	lst_size(t_cmd *cmd)
{
	t_token *liste;
	int		len;

	liste = cmd->args;
	len = 0;
	while (liste)
	{
		len++;
		liste = liste->next;
	}
	return (len);
}

char	**list_to_tab(t_cmd *cmd)
{
	t_token	*liste;
	int		len;
	int		i;
	char	**aaargs;

	len = lst_size(cmd);
	aaargs = malloc(sizeof(char *) * len + 2);
	if (aaargs == NULL)
		return (NULL);
	liste = cmd->args;
	aaargs[0] = ft_strdup(cmd->cmd);
	i = 1;
	while (liste)
	{
		aaargs[i] = ft_strdup(liste->word);
		i++;
		liste = liste->next;
	}
	aaargs[i] = NULL;
	return(aaargs);
}

	// (void)cmd;
	// char *args[] = {"/bin/ls", NULL} ;
	// ft_print_tab(aaaaaaaaargs, 0);

char	*check_path(t_cmd *cmd)
{
	char		**path;
	char		*binary;
	struct stat	stats;
	
	int		i;
	(void)cmd;

	path = ft_split(find_env(g_ms->env, "PATH"), ":");
	i = 0;
	while (path[i])
	{
		binary = ft_strjoin(path[i], "/");
		binary = ft_strjoin_free(binary, cmd->cmd, 'L');
		if (lstat(binary, &stats) == 0)
			return (binary);
		i++;
	}
	return (NULL);
}

//void	exec_command(char *binary, char **args)
//{
//	pid_t	pid;

//	pid = fork();
//	if (pid < 0)
//		print_error("Error forking\n");
//	if (pid == 0) // Processus enfant
//	{
//		printf("Child process	%d\n", getpid());
//		// ancer create_pipe() ??
//		execve(binary, args, NULL);
//		kill(pid, SIGKILL);
//	}
//	if (pid > 0) // Processus parent
//	{
//		printf("Parent process	%d\n", getpid());
//		wait(NULL);
//		// kill(pid, SIGKILL);
//	}
//}

void	exec_command(t_cmd *cmd,char *binary, char **args, int fd[2])
{
	//int fd[2];
	pid_t pid;
	int fdd = 0;

	//while (*cmd != NULL)
	//{
		///* create the pipe */
		//if (pipe(fd) == -1)
		//	print_error("pipe failled\n");
		printf("%d\n", cmd->out);
		printf("%d\n", cmd->next->in);
		ft_putstr_fd("FDPPPPPPPPPPPPPPPPPPPP", cmd->next->in);

		/* create the child */
		pid = fork();
		if (pid < 0)
			print_error("fork failled\n");

		/* child process */
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (cmd->type == PIPE)
				dup2(fd[WRITE], 1);
			close(fd[READ]);
			execvp(binary, args);
			exit(1);
		}

		/* parent process */
		else
		{
			wait(NULL);			/* Collect childs */
			close(fd[WRITE]);
			fdd = fd[READ];
			//cmd++;
		}
	//}
}

int	start_command(t_cmd *cmd, int fd[2])
{
	char	*binary;
	char	**args;

	args = list_to_tab(cmd);
	binary = check_path(cmd);
	if (binary)
		exec_command(cmd, binary, args, fd);
	else
		exec_command(cmd, cmd->cmd, args, fd);
	return (0);
}
