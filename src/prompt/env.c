#include "minishell.h"

t_env	*lst_new_env(char *name, char *value)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return (NULL);
	tmp->name = name;
	tmp->value = value;
	tmp->next = NULL;
	return (tmp);
}

void	add_env(t_env **alst, t_env *new)
{
	while (*alst)
		alst = &(*alst)->next;
	*alst = new;
}

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

int	init_env(char **env)
{
	char	**array;
	char	*tmp;
	int		i;

	i = -1;
	while (env[++i])
	{
		array = ft_split(env[i], "=");
		if (!array)
			return (0);
		if (!array[1])
			tmp = "";
		else
			tmp = ft_strdup(array[1]);
		add_env(&g_ms->env, lst_new_env(ft_strdup(array[0]), tmp));
		ft_free_tab(array);
	}
	return (1);
}

void	free_env(void)
{
	t_env	*tmp;

	while (g_ms->env)
	{
		tmp = g_ms->env->next;
		free(g_ms->env->name);
		free(g_ms->env->value);
		free(g_ms->env);
		g_ms->env = tmp;
	}
}

void	set_env(char* env, char *value)
{
	t_env	*tmp;
	t_env	*tmp2;
	char	*tmp3;

	tmp = g_ms->env;
	while (tmp)
	{
		tmp2 = tmp;
		if (ft_strcmp(env, tmp2->name) == 0)
		{
			tmp3 = tmp2->value;
			tmp2->value = ft_strdup(value);
			free(tmp3);
			return ;
		}
		tmp = tmp->next;
	}
}