#include "minishell.h"

int		env_size(char *src, int i)
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
