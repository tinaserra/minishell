#include "minishell.h"

/**
 * lst_new_env
 * * create new t_env element
 * @param name name of env variable
 * @param name value of env variable
 */

t_env	*lst_new_env(char *name, char *value)
{
	t_env	*tmp;

	if ((tmp = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	tmp->name = name;
	tmp->value = value;
	tmp->next = NULL;
	return (tmp);
}

/**
 * add_env
 * * add env variable to the end of list
 * @param alst pointer on list
 * @param new new element
 */

void	add_env(t_env **alst, t_env *new)
{
	while (*alst)
		alst = &(*alst)->next;
	*alst = new;
}

/**
 * find_env
 * * find env variable in chained list
 * @param env environment variables
 * @param name variable name
 */

char	*find_env(t_env *env, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * init_env
 * * store environment variables in ms.env structure
 * @param ms minishell structure
 * @param env environment variables
 */

int		init_env(char **env)
{
	char	**tabb;
	char	*tmp;
	int		i;

	i = -1;

	while (env[++i])
	{
		if ((tabb = ft_split(env[i], "=")) == NULL)
			return (0);
		tmp = tabb[1] == NULL ? "" : ft_strdup(tabb[1]);
		add_env(&ms->env, lst_new_env(ft_strdup(tabb[0]), tmp));
		//TODO: free tabb
	}
	return (1);
}
