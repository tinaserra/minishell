/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:08:05 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/21 10:01:37 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env(char **env)
{
	char	**array;
	char	*tmp;
	int		i;

	i = -1;
	while (env[++i])
	{
		array = ft_split(env[i], "=");
		if (!array)
			return (0);
		if (!array[1])
			tmp = "";
		else
			tmp = ft_strdup(array[1]);
		add_env(&g_ms->env, lst_new_env(ft_strdup(array[0]), tmp));
		ft_free_tab(array);
	}
	return (1);
}

void	free_env(void)
{
	t_env	*tmp;

	if (!g_ms->env)
		return ;
	while (g_ms->env)
	{
		tmp = g_ms->env->next;
		free(g_ms->env->name);
		free(g_ms->env->value);
		free(g_ms->env);
		g_ms->env = tmp;
	}
}

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
	if (!pwd[0])
	{
		free(pwd);
		res = ft_strjoin_free(res, "/", 'L');
	}
	else
	{
		res = ft_strjoin_free(res, pwd[ft_strs_tab_size(pwd) - 1], 'L');
		ft_free_tab(pwd);
	}
	res = ft_strjoin_free(res, " \x1b[0m", 'L');
	return (res);
}
