#include "minishell.h"

void fonction(t_minishell *ms, char **path)
{
	(void)ms;
	(void)path;

	printf("%s\n", ms->env.path[1]);

}