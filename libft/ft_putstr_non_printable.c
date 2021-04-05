/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:15:36 by vserra            #+#    #+#             */
/*   Updated: 2019/08/04 22:24:05 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	change(int str)
{
	char *hexa;

	if (str < 0)
		str += 256;
	hexa = "0123456789abcdef";
	write(1, "\\", 1);
	if (str > 15)
	{
		write(1, &hexa[str / 16], 1);
		write(1, &hexa[str % 16], 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, &hexa[str], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < ' ') || str[i] > '~')
			change(str[i++]);
		else
			write(1, &str[i++], 1);
	}
}