/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:26:04 by vserra            #+#    #+#             */
/*   Updated: 2021/06/23 16:23:35 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	a;
	unsigned int	i;

	a = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			a = i;
		}
		while (a)
		{
			if (tab[a - 1] > tab[a])
			{
				ft_swap(&tab[a - 1], &tab[a]);
				--a;
			}
			else
				a = 0;
		}
		++i;
	}
}
