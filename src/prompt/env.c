/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:51:28 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/05 14:53:21 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*lst_new_env(char *name, char *value)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return (NULL);
	tmp->name = name;
	tmp->value = ft_strdup(value);
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

t_env	*get_env(t_env *env, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	set_env(char *env, char *value)
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
