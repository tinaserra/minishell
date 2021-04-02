/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:13:56 by vserra            #+#    #+#             */
/*   Updated: 2021/04/02 18:08:24 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** In tribute to our friend Doris.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void *nemo;

	if (!(nemo = malloc(count * size)))
		return (NULL);
	ft_bzero(nemo, count * size);
	return (nemo);
}