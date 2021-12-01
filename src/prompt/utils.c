/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:08:05 by jode-vri          #+#    #+#             */
/*   Updated: 2021/12/01 13:04:23 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*lst_new_env(char *name, char *value, int show, int show2)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return (NULL);
	tmp->name = name;
	tmp->show = show;
	tmp->show2 = show2;
	tmp->value = ft_strdup(value);
	tmp->next = NULL;
	return (tmp);
}

static int	check_env(char **env)
{
	if (env && !env[0])
	{
		add_env(&g_ms->env, lst_new_env(ft_strdup("PWD"), getcwd(NULL, 0),
				1, 1));
		add_env(&g_ms->env, lst_new_env(ft_strdup("PATH"), "/bin", 1, 1));
		return (1);
	}
	return (0);
}

int	init_env(char **env)
{
	char	**array;
	char	*tmp;
	int		i;

	i = -1;
	if (check_env(env))
		return (1);
	while (env && env[++i])
	{
		if (env[i][0] != '\0')
		{
			array = ft_split(env[i], "=");
			if (!array)
				return (0);
			if (!array[1])
				tmp = "";
			else
				tmp = array[1];
			add_env(&g_ms->env, lst_new_env(ft_strdup(array[0]), tmp, 1, 1));
			ft_free_tab(array);
		}			
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
	if (pwd)
	{
		res = ft_strjoin_free(res, pwd[ft_strs_tab_size(pwd) - 1], 'L');
		ft_free_tab(pwd);
	}
	res = ft_strjoin_free(res, " \x1b[0m", 'L');
	return (res);
}
