/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/09/15 08:42:25 by jode-vri         ###   ########.fr       */
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

void	exec_command(t_cmd *cmd, char *binary, char **args)
{
	pid_t pid;
	(void)cmd;
	
	pid = fork();
	if (pid < 0)
		print_error("fork failled\n");

	/* child process */
	else if (pid == 0)
	{
		execve(binary, args, NULL);
		exit(1);
	}
	else
		wait(NULL);
}

void exec_command_pipe(char *cmd, char *cmd2, char **s1, char **s2)
{
	
	int fd[2];
	pid_t pid;
	pid_t pid2;
	int	status;
	int	status2;

	if (pipe(fd) == -1)
		printf("Erreur pipe\n");
	pid = fork();
	if (pid == 0)
	{
		//commande 1
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(cmd, s1, NULL);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		//commande 2
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execve(cmd2, s2, NULL);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status2, 0);
}


int	start_command(t_cmd *cmd)
{
	char	*binary;
	char	*binary2;
	char	**args;
	char	**args2;

	args = list_to_tab(cmd);
	binary = check_path(cmd);
	if (cmd->type == PIPE)
	{
		binary2 = check_path(cmd->next);
		args2 = list_to_tab(cmd->next);
		if (binary)
			exec_command_pipe(binary, binary2, args, args2);
		else
			exec_command_pipe(cmd->cmd, cmd->next->cmd, args, args2);
	}
	else
	{
		if (binary)
			exec_command(cmd, binary, args);
		else
			exec_command(cmd, cmd->cmd, args);
	}
	return (0);
}
