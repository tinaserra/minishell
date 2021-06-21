/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:41:21 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 12:31:18 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*save;

	save = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (save->next)
			save = save->next;
		save->next = new;
	}
}
