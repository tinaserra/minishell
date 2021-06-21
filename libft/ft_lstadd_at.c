/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:42:30 by tinaserra         #+#    #+#             */
/*   Updated: 2021/06/21 13:07:49 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	useless_function(t_list	*prec, t_list	*cur)
{
	prec = cur;
	cur = cur->next;
}

t_list	*ft_lstadd_at(t_list *l, void *data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	t_list	*cell;
	int		i;

	prec = l;
	cur = l;
	cell = ft_lstcreate(data);
	if (l == NULL)
		return (cell);
	if (pos == 0)
	{
		cell->next = l;
		return (cell);
	}
	if (pos > ft_lstsize(l))
		return (NULL);
	i = -1;
	while (++i < pos)
		useless_function(prec, cur);
	prec->next = cell;
	cell->next = cur;
	return (l);
}
