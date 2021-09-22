/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:08:05 by jode-vri          #+#    #+#             */
/*   Updated: 2021/09/22 19:59:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*print_prompt(void)
{
	char	**pwd;
	char	*res;

	res = NULL;
	pwd = ft_split(find_env(g_ms->env, "PWD"), "/");
	res = ft_strjoin(res, "\x1b[33m");
	res = ft_strjoin_free(res, find_env(g_ms->env, "USER"), 'L');
	res = ft_strjoin_free(res, "\x1b[31m ➜ ", 'L');
	res = ft_strjoin_free(res, "\x1b[34m ", 'L');
	res = ft_strjoin_free(res, pwd[ft_strs_tab_size(pwd) - 1], 'L');
	res = ft_strjoin_free(res, " \x1b[0m", 'L');
	ft_free_tab(pwd);
	return (res);
}
