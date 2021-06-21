/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:15:45 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 12:16:19 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int *power, int nbr, char *base)
{
	int	length;
	int	len_base;

	length = 1;
	*power = 1;
	if (nbr < 0)
	{
		*power = -1;
		length = 1;
	}
	len_base = ft_strlen(base);
	while (nbr <= (-(len_base)) || nbr >= len_base)
	{
		nbr = nbr / len_base;
		*power = *power * len_base;
		length++;
	}
	return (length);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		power;
	int		length;
	int		i;
	char	*out;

	if (ft_check_base(base) == 0)
		return (NULL);
	length = ft_nbrlen(&power, nbr, base);
	out = malloc(length + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
		out[i++] = '-';
	while (power != 0)
	{
		out[i++] = base[nbr / power];
		nbr = nbr - (nbr / power) * power;
		power = power / ft_strlen(base);
	}
	out[i] = '\0';
	return (out);
}
