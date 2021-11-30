/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:24:33 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/30 07:42:22 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(void)
{
	char	*tmp;

	tmp = ft_strdup(g_ms->curdir);
	free(g_ms->curdir);
	g_ms->curdir = NULL;
	if (find_env(g_ms->env, "PWD") && find_env(g_ms->env, "OLDPWD"))
		set_env("OLDPWD", find_env(g_ms->env, "PWD"));
	g_ms->curdir = getcwd(NULL, 0);
	if (!g_ms->curdir)
	{
		error("unable to retrieve current directory", "cd", NULL, 1);
		g_ms->curdir = ft_strjoin(tmp, "/");
		return ;
	}
	if (find_env(g_ms->env, "PWD"))
		set_env("PWD", g_ms->curdir);
	free(g_ms->term);
	g_ms->term = print_prompt();
	free(tmp);
}

int	have_permission(t_token *token)
{
	DIR	*dir;

	errno = 0;
	dir = opendir(token->word);
	if (dir == NULL || errno != 0)
	{
		error(strerror(errno), "cd", token->word, 1);
		return (0);
	}
	else
		closedir(dir);
	return (1);
}

int	cd_2(t_token *tmp)
{
	if (tmp)
	{
		if (tmp->word[0] == '\0')
			return (0);
		if (have_permission(tmp) && chdir(tmp->word) != 0)
		{
			error(strerror(errno), "cd", tmp->word, 1);
			g_ms->status = 1;
			return (0);
		}
		return (1);
	}
	return (0);
}

int	cd_check(t_token *tmp)
{
	if (tmp && tmp->next)
	{
		error("too many arguments", "cd", NULL, 1);
		return (0);
	}
	return (1);
}

void	cd_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	*s;

	tmp = cmd->args;
	if (tmp && !ft_strcmp(cmd->cmd, tmp->word))
		tmp = tmp->next;
	if (!cd_check(tmp))
		return ;
	if (!tmp)
	{
		s = find_env(g_ms->env, "HOME");
		if (!s || chdir(s) != 0)
			return ;
	}
	else
	{
		if (tmp->type == EXIT_STATUS)
		{
			free(tmp->word);
			tmp->word = ft_itoa(g_ms->status);
		}
		if (!cd_2(tmp))
			return ;
	}
	update_pwd();
}
