/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:42:30 by tinaserra         #+#    #+#             */
/*   Updated: 2021/04/13 03:04:34 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_at(t_list *l, void *data, int pos)
{
	t_list *prec;
	t_list *cur;
	t_list *cell;
	int i;

	prec = l;
	cur = l;
	cell = ft_lstcreate(data);
	if (l == NULL)
		return(cell);
	if (pos == 0)
	{
		cell->next = l;
		return(cell);
	}
	if (pos > ft_lstsize(l))
		return (NULL);
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return(l);
}
