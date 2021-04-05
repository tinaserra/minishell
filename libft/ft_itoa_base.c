/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:15:45 by vserra            #+#    #+#             */
/*   Updated: 2019/08/15 03:23:32 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int *power, int nbr, char *base)
{
	int		length;

	length = 1;
	*power = 1;
	if (nbr < 0)
	{
		*power = -1;
		length = 1;
	}
	while (nbr <= (-(ft_strlen(base))) || nbr >= ft_strlen(base))
	{
		nbr = nbr / ft_strlen(base);
		*power = *power * ft_strlen(base);
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
	if (!(out = malloc(length + 1)))
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
