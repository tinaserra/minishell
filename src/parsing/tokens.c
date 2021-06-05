/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 23:41:36 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/05 06:40:53 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		*create_token(int i)
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

void		add_token(t_token **start, t_token *new)
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

t_token		*create_token2(char *word, int type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
}

int	split_ms(int i, char *s, char *chset, int type)
{
	if (type == 1 && is_in_str(chset, s[i]) && !is_in_str(chset, s[i + 1])
		&& !is_in_quote(s, i) && !is_escaped(s, i - 1))
		return (1);
	else if (!type && is_in_str(chset, s[i]) && i > 0
		&& is_in_str(chset, s[i - 1]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	else if (type == 2 && is_in_str(chset, s[i])
		&& i > 0 && is_in_str(chset, s[i - 1]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	else if (type == 3 && is_in_str(chset, s[i]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	return (0);
}

int	split_minishell2(char *s, int *i, t_token **start)
{
	if (is_in_str(" ", s[*i]) && !is_in_quote(s, *i)
		&& !is_escaped(s, *i - 1))
	{
		add_token(start, create_token(*i));
		(*i)++;
		return (0);
	}
	if (is_in_str(";|<>", s[*i]) && !is_in_quote(s, *i)
		&& !is_escaped(s, *i - 1) && *i > 0 && !is_in_str("<>", s[*i - 1]))
		add_token(start, create_token(*i));
	return (1);
}

int		get_token_type(void)
{
	t_token	*tmp;
	
	tmp = g_ms->tokens;
	while (tmp)
	{
		if (ft_strcmp(tmp->word, ";") == 0)
			tmp->type = 0;
		else if (ft_strcmp(tmp->word, "|") == 0)
			tmp->type = 1;
		else if (ft_strcmp(tmp->word, "<") == 0
			|| ft_strcmp(tmp->word, "<<") == 0
			|| ft_strcmp(tmp->word, ">") == 0
			|| ft_strcmp(tmp->word, ">>") == 0)
			tmp->type = 2;
		else if (is_valid_env_var(tmp->word))
			tmp->type = 3;
		else
			tmp->type = 4;
		tmp = tmp->next;
	}
	return (1);
}

void	split_minishell(char *cmd)
{
	int		i;
	t_token	**start;

	i = 0;
	start = &g_ms->tokens;
	while (cmd[i])
	{
		if (!split_minishell2(cmd, &i, start))
			continue ;
		g_ms->count++;
		if (split_ms(i, cmd, ";|", 3) || split_ms(i, cmd, ">", 1)
			|| split_ms(i, cmd, ">", 0) || split_ms(i, cmd, "<", 1)
			|| split_ms(i, cmd, "<", 0))
			add_token(start, create_token(i + 1));
		i++;
	}
	if (i > 0)
		add_token(&g_ms->tokens, create_token(i));
}