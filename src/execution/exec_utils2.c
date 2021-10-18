/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:44 by vserra            #+#    #+#             */
/*   Updated: 2021/10/17 16:01:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	status_child(int status)
{
	if (WIFEXITED(status))
		g_ms->status = WEXITSTATUS(status);
	if (WIFSIGNALED(g_ms->pid))
	{
		g_ms->status = WTERMSIG(g_ms->pid);
		if (g_ms->status != 131)
			g_ms->status += 128;
	}
}

char	*find_binary(t_cmd *cmd, int show)
{
	struct stat	stats;
	char		*binary;

	binary = check_path(cmd);
	if (!binary)
	{
		if (lstat(cmd->cmd, &stats))
		{
			if (show){}
				//error("command not found", cmd->cmd, NULL, 127);
			free(binary);
			return (NULL);
		}
		free(binary);
		if (S_ISDIR(stats.st_mode) != 0)
			return (NULL);
		binary = ft_strdup(cmd->cmd);
	}
	return (binary);
}

int	find_all_binary(t_cmd *cmd)
{
	t_cmd	*tmpp;
	char	*bin;

	tmpp = cmd;
	while (tmpp)
	{
		bin = find_binary(tmpp, 1);
		if (!bin)
		{
			free(bin);
			return (0);
		}
		free(bin);
		tmpp = tmpp->next;
	}
	return (1);
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
	{
		if (s[i] == '\"' && !s_quote)
		{
			if (d_quote == 1)
				d_quote = 0;
			else
				d_quote = 1;
		}
		if (s[i] == '\'' && !d_quote)
		{
			if (s_quote == 1)
				s_quote = 0;
			else
				s_quote = 1;
		}
	}
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
