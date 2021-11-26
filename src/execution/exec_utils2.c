/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:44 by vserra            #+#    #+#             */
/*   Updated: 2021/11/26 17:56:57 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*openndir(char *path, char *cmd)
{
	DIR				*dir;
	struct dirent	*dirr;

	dir = opendir(path);
	if (dir)
	{
		dirr = readdir(dir);
		while (dirr)
		{
			if (ft_strcmp(dirr->d_name, cmd) == 0)
			{
				if (dir)
					closedir(dir);
				return (ft_strjoin(path, cmd));
			}
		}
	}
	if (dir)
		closedir(dir);
	return (NULL);
}

char	*find_binary(t_cmd *cmd, int show)
{
	char	*t;
	int		i;

	(void)show;
	i = 0;
	if (!cmd)
		return (NULL);
	if (is_in_str(cmd->cmd, '/') > 0)
		return (ft_strdup(cmd->cmd));
	if (cmd->bin)
	{
		t = openndir(cmd->bin, cmd->cmd);
		if (t)
			return (t);
	}
	return (check_path(cmd));
}

static void	count_quote2(char *s, int *i, int *d_quote, int *s_quote)
{
	if (s[*i] == '\"' && !*s_quote)
	{
		if (*d_quote == 1)
			*d_quote = 0;
		else
			*d_quote = 1;
	}
	if (s[*i] == '\'' && !*d_quote)
	{
		if (*s_quote == 1)
			*s_quote = 0;
		else
			*s_quote = 1;
	}
}

static int	count_quote(char *s)
{
	int	i;
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	i = -1;
	while (s && s[++i])
		count_quote2(s, &i, &d_quote, &s_quote);
	if (s_quote || d_quote)
		return (-1);
	else
		return (1);
}

int	edit_args(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	if (count_quote(cmd->cmd) == -1)
	{
		printf("minishell: Unclosed quote\n");
		return (0);
	}
	cmd->cmd = handle_quotes(cmd->cmd, 1);
	while (tmp)
	{
		if (count_quote(tmp->word) == -1)
		{
			printf("minishell: Unclosed quote\n");
			return (0);
		}
		tmp->word = handle_quotes(tmp->word, 1);
		tmp = tmp->next;
	}
	return (1);
}
