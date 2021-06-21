/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:40:18 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:33:35 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** haystack	-> La botte de foin
** needle	-> L'aguille
**
** On cherche la chaine 'needle' dans la chaine 'haystack'
*/

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return (haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
