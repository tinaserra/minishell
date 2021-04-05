#include "minishell.h"

void fonction(t_minishell *ms)
{
	//pid_t	pid;
	//int		status;

	printf("[%s]\n", ms->line);
	/*pid = 0;
	if ((pid == fork()) == 0)
	{
		if ((execve(ms->line, NULL, NULL)) == -1)
			exit(errno);
	}*/
	//else
	//	waitpid(pid, &status, 0);
}