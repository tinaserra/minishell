#include "minishell.h"

typedef struct	s_env2
{
	char	*content;
}				t_env2;

int	get_env_content(char **env_content)
{
	char			*pos;
	unsigned int	len;
	char			*env;

	pos = ft_strchr((char *)ms->line, '$');
	pos++;
	len = 0;
	while (*pos != '\0' && *pos != '"' && *pos != '\'' && *pos != ' ') // is_print
	{
		len++;
		pos++;
	}
	pos -= len;
	env = ft_strndup(pos, len);
	*env_content = getenv(env);
	printf("%s\n", *env_content);
	pos--;
	return (len);
}

void parsing()
{
	char	*env_content;
	char	*s1;
	char	*s2;
	int		len;

	int		i;

	i = 0;
	len = 0;
	ft_strtrim((char *)ms->line, "\f\t\n\r\v ");

	// -> $a : 
	// -> "$a" :
	// -> "..."$a"..." : remplaer la variable d'env et gerer la string les ""
	len = get_env_content(&env_content);
	while (ms->line[i] != '$')
		i++;
	s1 = ft_strndup((char *)ms->line, i);
	ms->line += len + i + 1;
	s2 = ft_strdup((char *)ms->line);
	printf("s1 [%s]\n", s1);
	printf("s2 [%s]\n", s2);
	// free(ms->line);
	ms->line = (unsigned char *)ft_strjoin_free(s1, env_content, 'Z');
	ms->line = (unsigned char *)ft_strjoin_free((char *)ms->line, s2, 'Z');
	printf("ms->line [%s]\n", ms->line);

}

void fonction() // parsing
{
	parsing();
}