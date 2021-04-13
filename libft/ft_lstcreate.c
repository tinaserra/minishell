/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:41:22 by tinaserra         #+#    #+#             */
/*   Updated: 2021/04/13 02:41:28 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(void *data)
{
	t_list *cell;

	if ((cell = malloc(sizeof(t_list))) == NULL)
		return(NULL);
	cell->data = data;
	cell->next = NULL;
	return(cell); 
}
