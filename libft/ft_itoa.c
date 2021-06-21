/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:57:20 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 12:12:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while ((n != 0) && (n <= -10 || n >= 10))
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_stocknbr(int n, char *str)
{
	int	i;
	int	power;
	int	save;

	i = -1;
	power = 1;
	save = n;
	if (n < 0)
	{
		i = 0;
		power = -1;
		str[i] = '-';
	}
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		power = power * 10;
	}
	while (power != 0)
	{
		str[++i] = save / power + '0';
		save = save - (save / power) * power;
		power = power / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*out;

	len = ft_len(n);
	out = malloc(sizeof(*out) * (len + 1));
	if (out == NULL)
		return (0);
	out = ft_stocknbr(n, out);
	out[len] = '\0';
	return (out);
}
