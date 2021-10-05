/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:54:59 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/05 14:55:00 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_escaped(char *s, int pos)
{
	int	i;

	i = 0;
	while (pos >= 0 && s[pos] == '\\')
	{
		i++;
		pos--;
	}
	return (i % 2);
}

int	is_in_quote(char *s, int pos)
{
	int	i;
	int	s_quote;
	int	d_quote;

	i = -1;
	s_quote = 0;
	d_quote = 0;
	while (++i <= pos)
	{
		if (s[i] == 34 && (i == 0 || !is_escaped(s, i - 1))
			&& d_quote % 2 == 0)
			s_quote++;
		if (s[i] == 39 && (i == 0 || d_quote % 2 != 0 || !is_escaped(s, i - 1))
			&& s_quote % 2 == 0)
			d_quote++;
	}
	if (s_quote % 2 != 0 || d_quote % 2 != 0)
		return (1);
	return (0);
}

int	is_in_str(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

int	is_valid_env_var(char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			return (2);
		if (s[i] == '$')
		{
			if (!ft_isalpha(s[i + 1]))
				return (0);
			j = i + 2;
			while (s[j] && !is_in_str(" $\"'\0", s[j]))
			{
				if (!ft_isalnum(s[j]) && s[j] != '_')
					return (0);
				j++;
			}
			return (1);
		}
	}
	return (0);
}

int	have_error(t_token *token)
{
	if ((token->type == PIPE || token->type == POINT_V) && !token->prev)
		return (1);
	if (token->type == REDIR && (token->prev && token->prev->type == REDIR))
		return (1);
	if (token->type == NEWL && token->prev && (token->prev->type == REDIR
			|| token->prev->type == PIPE))
		return (1);
	if ((token->type == PIPE || token->type == POINT_V)
		&& (token->prev->type == PIPE || token->prev->type == POINT_V
			|| token->prev->type == REDIR))
		return (1);
	return (0);
}
