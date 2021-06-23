/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:32:42 by vserra            #+#    #+#             */
/*   Updated: 2021/06/23 16:34:13 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char *str, int c)
{
	int		i;
	int		j;
	int		len;
	char	*out;

	i = 0;
	while (str[i] != c)
		i++;
	i++;
	len = 0;
	while (str[i + len] != c)
		len++;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	j = 0;
	while (str[i] && j < len)
	{
		out[j] = str[i];
		j++;
		i++;
	}
	out[j] = '\0';
	return (out);
}
