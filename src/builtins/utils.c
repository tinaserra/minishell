/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:55 by jode-vri          #+#    #+#             */
/*   Updated: 2021/12/01 13:05:08 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lstfind_pos(t_env *lst, char *name)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}

int	lstsize(t_env *l)
{
	int	len;

	len = 0;
	while (l)
	{
		len++;
		l = l->next;
	}
	return (len);
}

void	cd_3(t_token *tmp)
{
	if (tmp->type == EXIT_STATUS)
	{
		free(tmp->word);
		tmp->word = ft_itoa(g_ms->status);
	}
}

t_env	*get_env2(t_env *env, char *name)
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
