/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:35:33 by vserra            #+#    #+#             */
/*   Updated: 2019/08/12 12:58:51 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nbr;

	if (ft_check_base(base) == 0)
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_strchr(base, str[i]))
	{
		nbr = nbr * ft_strlen(base);
		nbr = nbr + (ft_strchr(base, str[i]) - base);
		i++;
	}
	return (nbr * sign);
}