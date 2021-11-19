/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:56:09 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/05 14:56:10 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_content(char *line, char **env_content)
{
	char			*pos;
	unsigned int	len;
	char			*env;

	pos = ft_strchr(line, '$');
	pos++;
	len = 0;
	while (*pos != '\0' && *pos != '"' && *pos != '\'' && *pos != ' ')
	{
		len++;
		pos++;
	}
	pos -= len;
	env = ft_strndup(pos, len);
	*env_content = getenv(env);
	pos--;
	free(env);
	return (len);
}

char	*replace_env(char *str, int pos_dollar)
{
	int		len;
	char	*env_content;
	char	*s1;
	char	*s2;

	len = get_env_content(&str[pos_dollar], &env_content);
	s1 = ft_strndup(str, pos_dollar);
	s2 = ft_strdup(&str[len + pos_dollar + 1]);
	str = ft_strjoin_free(s1, env_content, 'L');
	str = ft_strjoin_free(str, s2, 'B');
	return (str);
}

int	env_size(char *src, int i)
{
	int		count;
	char	buf[4096];

	count = 0;
	ft_bzero(buf, sizeof(buf));
	i++;
	while (src[i] && (ft_isalnum(src[i]) || is_in_str("?_", src[i])))
	{
		if (ft_isdigit(src[i]) && count == 0)
			return (0);
		buf[count] = src[i];
		if (src[i] == '?' && count == 0)
			break ;
		i = i + 1;
		count++;
	}
	if (find_env(g_ms->env, buf))
		count = ft_strlen(find_env(g_ms->env, buf));
	return (count);
}

char	*replace_env2(char *str, int *i)
{
	int		count;
	char	buf[4096];
	char	*new;

	new = ft_strdup("");
	count = 0;
	(*i)++;
	ft_bzero(buf, sizeof(buf));
	while (str[*i] && (ft_isalnum(str[*i]) || is_in_str("?_", str[*i])))
	{
		buf[count] = str[*i];
		*i = *i + 1;
		if (str[*i - 1] == '?' && count == 0)
			break ;
		if (ft_isdigit(str[*i - 1]) && count == 0)
			return (new);
		count++;
	}
	new = ft_strjoin_free(new, find_env(g_ms->env, buf), 'L');
	return (new);
}
