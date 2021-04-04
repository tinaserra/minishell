#include "minishell.h"

void init_env(t_minishell *ms, char **env)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	(void)ms;
	i = -1;
	while (env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (ft_strcmp(tmp[0], "PWD"))
		{
			tmp2 = ft_split(tmp[1], "/");
			ms->env.pwd = tmp2[ft_strs_tab_size(tmp2) - 3];
			free(tmp2);
		}
		free(tmp);
	}
}