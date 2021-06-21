/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:52:21 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:52:22 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *l)
{
	if (l == NULL)
		printf("la liste est vide\n");
	while (l != NULL)
	{
		printf("[%s]\n", (char *)l->data);
		l = l->next;
	}
	printf("\n");
}
