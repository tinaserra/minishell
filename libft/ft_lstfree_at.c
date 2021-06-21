/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:39:06 by tinaserra         #+#    #+#             */
/*   Updated: 2021/06/21 13:09:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	useless_function(t_list	*prec, t_list	*cur)
{
	prec = cur;
	cur = cur->next;
}

t_list	*ft_lstfree_at(t_list *l, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;

	prec = l;
	cur = l;
	if (l == NULL)
		return (NULL);
	if (pos == 0)
	{
		l = l->next;
		free(cur);
		return (l);
	}
	if (pos > ft_lstsize(l))
		return (NULL);
	i = -1;
	while (++i < pos)
		useless_function(prec, cur);
	prec->next = cur->next;
	free(cur);
	return (l);
}
