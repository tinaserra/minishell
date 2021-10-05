/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:55 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/05 14:41:02 by jode-vri         ###   ########.fr       */
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
