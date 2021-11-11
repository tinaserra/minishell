/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:56:27 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 15:16:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*double_quotes(char *src, int *i, int j, int env)
{
	char	*dest;
	char	*tmp;
	int		k;

	k = quote_size(src + *i, 1, env);
	dest = (char *)ft_calloc(1, k + 1);
	while (src[*i] && j < k)
	{
		if (src[*i] == '\"' && !is_escaped(src, *i - 1))
			break ;
		if (src[*i] == '$' && !is_escaped(src, *i - 1) && env
			&& (ft_isalnum(src[*i + 1]) || is_in_str("?_", src[*i + 1])))
		{
			tmp = replace_env2(src, i);
			j = ft_strlcat(dest, tmp, k);
			free(tmp);
			continue ;
		}
		if ((src[*i] != '\\' || is_escaped(src, *i - 1) || (src[*i + 1] != '\"'
					&& src[*i + 1] != '\\' && src[*i + 1] != '$')) && j < k)
			dest[j++] = src[*i];
		(*i)++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*no_quotes(char *src, int *i, int j, int env)
{
	char	*dest;
	char	*tmp;
	int		k;

	k = quote_size(src + *i, 0, env);
	dest = (char *)ft_calloc(1, k + 5);
	while (src[*i] && j < k)
	{
		if ((src[*i] == '\'' || src[*i] == '\"') && !is_escaped(src, *i - 1))
			break ;
		if (src[*i] == '$' && !is_escaped(src, *i - 1) && env
			&& (ft_isalnum(src[*i + 1]) || is_in_str("?_", src[*i + 1])))
		{
			tmp = replace_env2(src, i);
			j = ft_strlcat(dest, tmp, k);
			free(tmp);
			continue ;
		}
		if ((src[*i] != '\\' || is_escaped(src, *i - 1)) && j < k)
			dest[j++] = src[*i];
		(*i)++;
	}
	dest[j] = '\0';
	return (dest);
}

static	void	uselesstruc(char *src, int *i)
{
	if (src[*i])
		i++;
}

char	*handle_quotes(char *src, int env)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == NULL)
		return (src);
	dest = ft_strdup("");
	while (src[i])
	{
		if (src[i] == '\'' && !is_escaped(src, i - 1))
			dest = ft_strjoin_free(dest, simple_quotes(src, &i), 'B');
		else if (src[i] == '\"' && !is_escaped(src, i - 1))
		{
			i++;
			dest = ft_strjoin_free(dest, double_quotes(src, &i, 0, env), 'B');
		}
		else
		{
			dest = ft_strjoin_free(dest, no_quotes(src, &i, 0, env), 'B');
			continue ;
		}
		uselesstruc(src, &i);
	}
	free(src);
	return (dest);
}
