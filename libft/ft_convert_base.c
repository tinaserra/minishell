/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:15:45 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 12:01:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	tmp;

	if (ft_check_base(base_from) == 0)
		return (NULL);
	tmp = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(tmp, base_to));
}
