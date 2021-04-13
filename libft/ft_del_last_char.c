/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:33:43 by jode-vri          #+#    #+#             */
/*   Updated: 2021/04/13 04:33:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_del_last_char(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s) - 1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	free(s);
	return (res);
}