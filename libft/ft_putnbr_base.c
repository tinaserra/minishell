/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:41:28 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:16:05 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;
	int	save;

	if (ft_check_base(base) == 0)
		return ;
	l = 1;
	save = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		l = -1;
	}
	while (nbr <= (-(ft_strlen(base))) || nbr >= ft_strlen(base))
	{
		nbr = nbr / ft_strlen(base);
		l = l * ft_strlen(base);
	}
	while (l != 0)
	{
		ft_putchar_fd(base[save / l], 1);
		save = save - (save / l) * l;
		l = l / ft_strlen(base);
	}
}
