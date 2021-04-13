/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:39:06 by tinaserra         #+#    #+#             */
/*   Updated: 2021/04/13 02:43:32 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfree_at(t_list *l, int pos)
{
	t_list *prec;
	t_list *cur;
	int i;

	prec = l;
	cur = l;
	if (l == NULL)
		return(NULL);
	if (pos == 0)
	{
		l = l->next;
		free(cur);
		return(l);
	}
	if (pos > ft_lstsize(l))
		return NULL;
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return(l);
}