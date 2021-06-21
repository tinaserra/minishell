/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:37:25 by tinaserra         #+#    #+#             */
/*   Updated: 2021/06/21 13:14:36 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstset_at(t_list *l, void *new_data, int pos)
{
	int	i;

	if (l == NULL || pos > ft_lstsize(l))
		return ;
	i = 0;
	while (i < pos)
	{
		l = l->next;
		i++;
	}
	l->data = new_data;
}
