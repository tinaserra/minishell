/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:08:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/30 13:44:09 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Si env + argument	-> $ env fnrf
** print une erreur		-> env: ‘fnrf’: No such file or directory
*/

void	export_x(int fd)
{
	t_env	*tmp;

	tmp = g_ms->env;
	if (fd == 0)
		fd = 1;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(tmp->name, fd);
		ft_putstr_fd("=\"", fd);
		ft_putstr_fd(tmp->value, fd);
		ft_putstr_fd("\"\n", fd);
		tmp = tmp->next;
	}
}

void	env_builtin(t_token *args, int fd)
{
	t_env	*tmp;

	tmp = g_ms->env;
	if (fd == 0)
		fd = 1;
	if (args)
	{
		error("No such file or directory", "env", args->word, 127);
		return ;
	}
	while (tmp)
	{
		ft_putstr_fd(tmp->name, fd);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(tmp->value, fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
