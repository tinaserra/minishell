/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:41:22 by tinaserra         #+#    #+#             */
/*   Updated: 2021/06/21 13:08:28 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(void *data)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (cell == NULL)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}
