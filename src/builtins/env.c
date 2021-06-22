/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:08:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/04 23:18:14 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(int fd)
{
	t_env	*tmp;

	tmp = g_ms->env;
	if (fd == 0)
		fd = 1;
	while (tmp)
	{
		ft_putstr_fd(fd, tmp->name);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(fd, tmp->value);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
