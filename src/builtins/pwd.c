/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:21:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/01 08:21:17 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_cmd *cmd)
{
	char	*pwd;

	if (cmd->out == 0)
		cmd->out = 1;
	pwd = find_env(g_ms->env, "PWD");
	if (pwd)
	{
		ft_putstr_fd(pwd, cmd->out);
		ft_putchar_fd('\n', cmd->out);
	}
}
