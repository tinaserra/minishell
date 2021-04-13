/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:35:47 by tinaserra         #+#    #+#             */
/*   Updated: 2021/04/13 02:48:19 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstget_at(t_list *l, int pos)
{
	int i;

	if (l == NULL || pos > ft_lstsize(l))
		return NULL;
	i = 0;
	while (i < pos)
	{
		l = l->next;
		i++;
	}
	return (l->data);
}
