/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:15:40 by admin             #+#    #+#             */
/*   Updated: 2021/11/11 15:22:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_size(char *src, int type, int env)
{
	int	i;
	int	j;
	int	esc;

	i = -1;
	j = 0;
	esc = 0;
	while (src[++i])
	{
		if (!esc && src[i] == '\'' && type == 2)
			return (i);
		if (!esc && src[i] == '\'' && type == 0)
			return (i + j);
		if (!esc && src[i] == '$' && (type == 0 || type == 1 || type == 4)
			&& env)
			j += env_size(src, i);
		if (!esc && src[i] == '\"' && (type == 0 || type == 1))
			return (i + j);
		esc = 0;
		if (src[i] == '\\' && type != 2)
			esc = 1;
		else
			esc = 0;
	}
	return (i + j);
}

char	*simple_quotes(char *src, int *i)
{
	char	*dest;
	int		j;

	(*i)++;
	j = quote_size(src + *i, 2, 0);
	dest = (char *)ft_calloc(1, j + 1);
	j = 0;
	while (src[*i] && src[*i] != '\'')
	{
		dest[j] = src[*i];
		*i = *i + 1;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

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
