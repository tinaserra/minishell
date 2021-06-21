/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:58:17 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 13:25:07 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = -1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}
