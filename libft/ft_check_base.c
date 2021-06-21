/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:41:28 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 11:59:59 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] && ft_strchr(&base[i + 1], base[i]) == NULL)
		i++;
	if (base[i])
		return (0);
	if (ft_strchr(base, '+') || ft_strchr(base, '-')
		|| ft_strchr(base, '\t') || ft_strchr(base, '\n')
		|| ft_strchr(base, '\r') || ft_strchr(base, '\v')
		|| ft_strchr(base, '\f') || ft_strchr(base, ' '))
		return (0);
	return (1);
}
