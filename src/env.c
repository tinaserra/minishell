#include "minishell.h"

void init_env(t_minishell *ms, char **env)
{
	char	**path;
	char	**user;

	(void)ms;

	path = ft_split(env[4], "=");
	user = ft_split(env[0], "=");
	ms->env.path = ft_split(path[1], ":");
	ms->env.user = user[1];
	free(path);
}