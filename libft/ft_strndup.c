/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:31:03 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:32:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t len)
{
	char	*out;
	size_t	i;

	i = -1;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	while (s1[++i] && i < len)
		out[i] = s1[i];
	out[i] = '\0';
	return (out);
}
