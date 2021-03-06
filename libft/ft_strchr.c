/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:58:47 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 13:22:57 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s && c)
	{
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
