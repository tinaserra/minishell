/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:52:39 by vserra            #+#    #+#             */
/*   Updated: 2021/06/21 13:52:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	res = malloc(size);
	ft_memcpy(res, ptr, size);
	return (res);
}
