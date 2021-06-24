/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:01:42 by vserra            #+#    #+#             */
/*   Updated: 2021/06/24 12:12:40 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **halo, int size)
{
	int	i;

	i = 0;
	(void)size;
	while (halo[i] != NULL)
	{
		printf("tab = %s\n", halo[i]);
		i++;
	}
}
