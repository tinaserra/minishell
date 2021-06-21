/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:51:43 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:51:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find_pos(t_list *lst, int pos)
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
