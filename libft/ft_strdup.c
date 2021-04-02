/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:58:17 by jode-vri          #+#    #+#             */
/*   Updated: 2021/02/25 17:19:12 by jode-vri         ###   ########.fr       */
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
	if ((result = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}