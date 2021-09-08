/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:42:30 by tinaserra         #+#    #+#             */
/*   Updated: 2021/09/08 12:16:47 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_at(t_list *l, void *data, int pos)
{
	(void)data;
	(void)pos;
	/*t_list	*prec;
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
	cell->next = cur;*/
	return (l);
}
