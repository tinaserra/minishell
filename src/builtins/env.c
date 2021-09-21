/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:08:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/24 15:45:05 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Si env + argument	-> $ env fnrf
** print une erreur		-> env: ‘fnrf’: No such file or directory
*/

void	env_builtin(int fd)
{
	t_env	*tmp;

	tmp = g_ms->env;
	if (fd == 0)
		fd = 1;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, fd);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(tmp->value, fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
