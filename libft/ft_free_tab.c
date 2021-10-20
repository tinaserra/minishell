/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:51:08 by vserra            #+#    #+#             */
/*   Updated: 2021/10/20 11:16:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab || !*tab)
		return ;
	while (++i <= ft_strs_tab_size(tab))
		free(tab[i]);
	free(tab);
}
