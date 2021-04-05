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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;

	if (ft_check_base(base_from) == 0)
		return (NULL);
	tmp = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(tmp, base_to));
}