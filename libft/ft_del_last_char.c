/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:33:43 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 12:03:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_del_last_char(char *s)
{
	char	*res;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	free(s);
	return (res);
}
