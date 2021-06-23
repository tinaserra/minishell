/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:51:43 by vserra            #+#    #+#             */
/*   Updated: 2021/06/23 16:23:22 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_pos(t_list *lst, int pos)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == pos)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
