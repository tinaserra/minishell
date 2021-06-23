/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:01:42 by vserra            #+#    #+#             */
/*   Updated: 2021/06/23 16:26:56 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **halo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab = %s\n", halo[i]);
		i++;
	}
}
