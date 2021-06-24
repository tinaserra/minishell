/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:08:05 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/24 15:46:54 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char	**pwd;

	pwd = ft_split(find_env(g_ms->env, "PWD"), "/");
	ft_putstr_fd("\x1b[33m", 1);
	ft_putstr_fd(find_env(g_ms->env, "USER"), 1);
	ft_putstr_fd("\x1b[31m ➜", 1);
	ft_putstr_fd("\x1b[34m ", 1);
	ft_putstr_fd(pwd[ft_strs_tab_size(pwd) - 1], 1);
	ft_putstr_fd(" \x1b[0m", 1);
	ft_free_tab(pwd);
	print_term("me");
}
