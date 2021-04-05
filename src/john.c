#include "minishell.h"

void fonction(t_minishell *ms)
{
	pid_t	pid;
	int		status;
	char	**args;

	get_cmds(ms);
	args = NULL;
	pid = 0;
	if ((pid == fork()) == 0)
	{
		execve(ms->cmds[0], ms->cmds, NULL);
	}
	else
		waitpid(pid, &status, 0);
}