/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:08:05 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/03 02:08:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * print_prompt
 * * print prompt
 * @param mode
 */

void	print_prompt(void)
{
	char	**pwd;

	pwd = ft_split(find_env(ms->env, "PWD"), "/");
	ft_putstr_fd(1, "\x1b[33m");
	ft_putstr_fd(1, find_env(ms->env, "USER"));
	ft_putstr_fd(1, "\x1b[31m ➜");
	ft_putstr_fd(1, "\x1b[34m ");
	ft_putstr_fd(1, pwd[ft_strs_tab_size(pwd) - 1]);
	ft_putstr_fd(1, " \x1b[0m");
	ft_free_tab(pwd);
	print_term("me");	
}