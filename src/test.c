/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/06/23 16:51:28 by vserra           ###   ########.fr       */
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
	ft_print_tab(aaargs, len + 2);
	return(aaargs);
}

int	ta_mere(t_cmd *cmd)
{
	(void)cmd;
	char *args[] = {"/bin/ls", NULL} ;

	char **aaaaaaaaargs;

	aaaaaaaaargs = list_to_tab(cmd);
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error with fork");
		// exit(EXIT_FAILURE);
	}
	if (pid == 0) // Processus enfant
	{
		printf("Child process	%d\n", getpid());
		execve("/bin/ls", args, NULL);
		kill(pid, SIGKILL);
	}
	if (pid > 0) // Processus parent
	{
		printf("Parent process	%d\n", getpid());
		wait(NULL);
		kill(pid, SIGKILL);
	}
	pid = 0;

	return (0);
}