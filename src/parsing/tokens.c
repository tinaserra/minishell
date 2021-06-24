/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 23:41:36 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/24 16:33:10 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(int i)
{
	t_token	*new;

	if (!g_ms->count)
		return (NULL);
	new = ft_calloc(1, sizeof(t_token));
	new->word = ft_substr(g_ms->line, i - g_ms->count,
				g_ms->count);
	g_ms->count = 0;
	return (new);
}

void	free_token(void)
{
	t_token	*tmp;

	while (g_ms->tokens)
	{
		tmp = g_ms->tokens->next;
		free(g_ms->tokens->word);
		free(g_ms->tokens);
		g_ms->tokens = tmp;
	}
	g_ms->tokens = NULL;
}

void	add_token(t_token **start, t_token *new)
{
	t_token	*tmp;

	if (!new || !start)
		return ;
	if (*start)
	{
		tmp = *start;
		while (tmp->next)
		{
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
		*start = new;
}

t_token	*create_token2(char *word, int type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
}

int	get_token_type(void)
{
	t_token	*tmp;

	tmp = g_ms->tokens;
	while (tmp)
	{
		if (ft_strcmp(tmp->word, ";") == 0)
			tmp->type = POINT_V; // point virgule
		else if (ft_strcmp(tmp->word, "|") == 0)
			tmp->type = PIPE;
		else if (ft_strcmp(tmp->word, "<") == 0
			|| ft_strcmp(tmp->word, "<<") == 0
			|| ft_strcmp(tmp->word, ">") == 0
			|| ft_strcmp(tmp->word, ">>") == 0)
			tmp->type = REDIR; // redirection
		else if (is_valid_env_var(tmp->word))
			tmp->type = ENV; //variable environnement
		else if (ft_strcmp(tmp->word, "\n") == 0)
			tmp->type = NEWL; // newline
		else
			tmp->type = TXT; // texte
		if (have_error(tmp))
		{
			g_ms->exit = 258;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
