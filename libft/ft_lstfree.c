/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:33:55 by tinaserra         #+#    #+#             */
/*   Updated: 2021/04/13 02:33:57 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfree(t_list *l)
{
	t_list *tmp;

	tmp = NULL;
	while(l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	return (l);
}