// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdlib.h>

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

void	ft_print_tab(char **halo, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("tab = %s\n", halo[i]);
		i++;
	}
}

char	**list_to_tab(t_cmd *cmd)
{
	t_token *liste;
	int		len;
	int		i;
	char	**salope;

	len = lst_size(cmd);
	salope = malloc(sizeof(char *) * len + 2);
	if (salope == NULL)
		return (NULL);
	liste = cmd->args;
	salope[0] = ft_strdup(cmd->cmd);
	i = 1;
	while (liste)
	{
		salope[i] = ft_strdup(liste->word);
		i++;
		liste = liste->next;
	}
	salope[i] = NULL;
	ft_print_tab(salope, len + 2);
	return(salope);
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
		perror("fork");
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