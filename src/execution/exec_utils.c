/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:30 by vserra            #+#    #+#             */
/*   Updated: 2021/10/12 10:17:00 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *s)
{
	if (ft_strcmp(s, "echo") == 0)
		return (1);
	if (ft_strcmp(s, "env") == 0)
		return (1);
	return (0);
}

static int	is_redirection(char *s)
{
	if (ft_strcmp(s, "<") == 0 || ft_strcmp(s, ">") == 0
		|| ft_strcmp(s, ">>") == 0 || ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}

static int	lst_size(t_cmd *cmd)
{
	t_token	*liste;
	int		len;

	liste = cmd->args;
	len = 0;
	while (liste)
	{
		if (!is_redirection(liste->word))
			len++;
		liste = liste->next;
	}
	return (len);
}

char	**list_to_tab(t_cmd *cmd)
{
	t_token	*liste;
	int		len;
	int		i;
	char	**aaargs;

	len = lst_size(cmd);
	aaargs = malloc(sizeof(char *) * (len + 2));
	if (aaargs == NULL)
		return (NULL);
	liste = cmd->args;
	aaargs[0] = ft_strdup(cmd->cmd);
	i = 1;
	while (liste)
	{
		if (!is_redirection(liste->word))
		{
			aaargs[i] = ft_strdup(liste->word);
			i++;
		}
		else
			liste = liste->next;
		if (liste)
			liste = liste->next;
	}
	aaargs[i] = NULL;
	return (aaargs);
}

char	*check_path(t_cmd *cmd)
{
	char		**path;
	char		*binary;
	struct stat	stats;
	int			i;

	path = ft_split(find_env(g_ms->env, "PATH"), ":");
	i = 0;
	while (path[i])
	{
		binary = ft_strjoin_free(ft_strdup(path[i]), "/", 'L');
		binary = ft_strjoin_free(binary, cmd->cmd, 'L');
		if (lstat(binary, &stats) == 0)
		{
			ft_free_tab(path);
			return (binary);
		}
		free(binary);
		i++;
	}
	ft_free_tab(path);
	return (NULL);
}
