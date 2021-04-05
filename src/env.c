#include "minishell.h"

/**
 * init_env
 * * store environment variables in ms.env structure
 * @param ms minishell structure
 * @param env environment variables
 */

void	init_env(t_minishell *ms, char **env)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	(void)ms;
	i = -1;
	while (env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (ft_strncmp(tmp[0], "PWD", 3) == 0)
		{
			tmp2 = ft_split(tmp[1], "/");
			ms->env.pwd = tmp2[ft_strs_tab_size(tmp2) - 1];
			free(tmp2);
		}
		if (ft_strncmp(tmp[0], "PATH", 4) == 0)
			ms->env.path = ft_split(tmp[1], ":");
		if (ft_strncmp(tmp[0], "USER", 4) == 0)
			ms->env.user = tmp[1];
		free(tmp);
	}
}
