#include "minishell.h"

int		get_env_content(char *line, char **env_content)
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
	return (len);
}

char	*replace_env(char *str, int pos_dollar)
{
	int		len;
	char	*env_content;
	char	*s1;
	char	*s2;

	len = get_env_content(&str[pos_dollar], &env_content);
	// while (env_content && ft_strchr(env_content, '$') != NULL)
	// 	len_content = get_env_content(&str[pos_dollar], &env_content);
	s1 = ft_strndup(str, pos_dollar);
	s2 = ft_strdup(&str[len + pos_dollar + 1]);
	str = ft_strjoin_free(s1, env_content, 'L');
	str = ft_strjoin_free(str, s2, 'B');
	return (str);
}
