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

char	*handle_quotes(char *src, int env)
{
	int		i;
	char	*dest;

	if (src == NULL)
		return (src);
	i = 0;
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
		if (src[i])
			i++;
	}
	free(src);
	src = NULL;
	return (dest);
}
