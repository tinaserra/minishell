/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:59:52 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 13:34:31 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
