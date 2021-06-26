/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/06/26 17:07:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	exec_command(char *binary, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_error("Error forking\n");
	if (pid == 0) // Processus enfant
	{
		printf("Child process	%d\n", getpid());
		// ancer create_pipe() ??
		execve(binary, args, NULL);
		kill(pid, SIGKILL);
	}
	if (pid > 0) // Processus parent
	{
		printf("Parent process	%d\n", getpid());
		wait(NULL);
		// kill(pid, SIGKILL);
	}
}

int	start_command(t_cmd *cmd, int ppipe[2])
{
	(void)ppipe;
	char	*binary;
	char	**args;

	args = list_to_tab(cmd);
	binary = check_path(cmd);
	if (binary)
		exec_command(binary, args);
	else
		exec_command(cmd->cmd, args);
	return (0);
}
