/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:26:35 by vserra            #+#    #+#             */
/*   Updated: 2021/10/21 10:19:15 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;
	t_list	*begin;

	begin = *lst;
	save = *lst;
	if (!lst)
		return ;
	if (*lst == NULL || !del)
		return ;
	while (save)
	{
		del(save->data);
		begin = save;
		save = save->next;
		free(begin);
	}
	*lst = NULL;
}
