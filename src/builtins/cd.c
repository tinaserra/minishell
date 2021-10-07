/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:24:33 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/07 14:56:34 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(void)
{
	free(g_ms->curdir);
	g_ms->curdir = NULL;
	if (find_env(g_ms->env, "PWD") && find_env(g_ms->env, "OLDPWD"))
		set_env("OLDPWD", find_env(g_ms->env, "PWD"));
	g_ms->curdir = ft_strdup(find_env(g_ms->env, "PWD"));

	if (find_env(g_ms->env, "PWD"))
		set_env("PWD", g_ms->curdir);
	free(g_ms->term);
	g_ms->term = print_prompt();
}

int	have_permission(t_cmd *cmd)
{
	DIR	*dir;

	errno = 0;
	dir = opendir(cmd->args->word);
	if (dir == NULL || errno != 0)
	{
		error(strerror(errno), "cd", cmd->args->word, 1);
		return (0);
	}
	else
		closedir(dir);
	return (1);
}

void	cd_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	*s;

	tmp = cmd->args;
	if (tmp->next)
	{
		error("too many arguments", "cd", NULL, 1);
		return ;
	}
	else if (!tmp)
	{
		s = find_env(g_ms->env, "HOME");
		if (!s || chdir(s) != 0)
		{
			error("HOME not set", "cd", NULL, 1);
			g_ms->exit = 1;
			return ;
		}
	}
	else
	{
		if (tmp->word[0] == '\0')
			return ;
		if (have_permission(cmd) && chdir(tmp->word) != 0)
		{
			error(strerror(errno), "cd", tmp->word, 1);
			g_ms->exit = 1;
			return ;
		}
	}
	update_pwd();
}
