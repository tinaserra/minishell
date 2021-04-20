#include "minishell.h"

void	print_list(t_list *l)
{
	if (l == NULL)
		printf("la liste est vide\n");
	while (l != NULL)
	{
		printf("[%s]\n", l->data);
		l = l->next;
	}
	printf("\n");
}

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

int		check_syntaxe()
{
	int		i;

	ms->mask = 0;
	i = 0;
	while (ms->line[i])
	{
		if (ms->line[i] == ';' && ms->line[i + 1] == ';')
		{	
			ft_putstr_fd(2, "syntax error near unexpected token `;;'\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// -> $a : 
// -> "$a" :
// -> "..."$a"..." : remplacer la variable d'env et gerer la string les ""

int		count_simple_quote(char *s, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (s[i] == '\'')
			ms->mask ^= SIMPLE_Q;
		i++;
	}
	if (ms->mask != 0) // nb impair de quote
		return (1);
	return (0);
}

	// AND &
	// 0 & 0 = 0
	// 0 & 1 = 0
	// 1 & 0 = 0
	// 1 & 1 = 1

int		truc(char *s)
{
	int i;
	int j;
	int dq;
	int sq;
	int quote;

	quote = 0;
	dq = 0;
	sq = 0;
	i = 0;
	while (s[i] != '\0')
	{
		printf("c: %c\n", s[i]);
		if (s[i] == '"' && sq == 0) // si le caracter = " et qu'on a pas encore trouver de quote (simple ou double)
		{
			quote = '"';
			printf("quote : %c\n", quote);
		}
		if (s[i] == '\'' && dq == 0)// si le caracter = ' et qu'on a pas encore trouver de quote (simple ou double)
		{
			quote = '\'';
			printf("quote : %c\n", quote);
		}
		j = i;
		while ((quote != 0) && (s[j] != quote || s[j] != '$'))
		{
			j++;
			printf("pd: %c\n", s[j]);
			printf("quote pd: %c\n", quote);
			if (s[j] == '$') // la variable est dans la boite actuelle
				return (quote);
			if (s[j] == quote)
			{
				printf("pd\n");
				quote = 0;
				break;
			}
		}
		i++;
	}
	return (0);
}

	// 					 0000 0001 & 0000 0010
	// savoir si une chaine est entre simple quote ou double quote

	// "......'$HOME'"	-> contenu
	// "..'..." '$HOME'	-> $HOME
	// "......'" $HOME	-> contenu
	// '......"$HOME"'	-> $HOME

	// parcoure la chaine et si " la plus grosse boite c'est " si le $ et dedans

	// if (str[i] == '"' && !(ms->mask & SIMPLE_Q))// on une double quote en premier
char	*replace_env(char *str)
{
	int		len;
	int		i;
	char	*env_content;
	char	*s1;
	char	*s2;

	i = 0;
	printf("truc %d\n", truc(str));
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			// if (count_simple_quote(str, i) == 1)
			// 	return (str);
			//printf("%d\n", count_simple_quote(str, i));
			len = get_env_content(&str[i], &env_content);
			s1 = ft_strndup(str, i);
			i = len + i + 1;
			s2 = ft_strdup(&str[i]);
			str = ft_strjoin_free(s1, env_content, 'L');
			str = ft_strjoin_free(str, s2, 'B');
			i = 0;
		}
		i++;
	}
	return (str);
}

int		parsing()
{
	int		i;
	int		old;
	char	*tmp;
	t_list	*commands;

	commands = NULL;
	if (check_syntaxe() == 0)
		return (0);
	ms->line = ft_strtrim(ms->line, "\f\t\n\r\v ");
	i = 0;
	old = 0;
	while (ms->line[i] != '\0')
	{
		if (ms->line[i] == '"')
			ms->mask ^= DOUBLE_Q;
		if (ms->line[i] == ';' || ms->line[i + 1] == '\0')
		{
			if (ms->mask == 0)
			{
				if (ms->line[i + 1] == '\0' && ms->line[i] != ';')
					tmp = ft_substr(ms->line, old, i - old + 1);
				else
					tmp = ft_substr(ms->line, old, i - old);
				tmp = ft_strtrim(tmp, "\f\t\n\r\v ");
				ft_lstadd_back(&commands, ft_lstcreate(tmp));
				old = i + 1;
			}
		}
		i++;
	}
	ms->commands = commands;
	commands = ms->commands;
	while (commands)
	{
		commands->data = replace_env(commands->data);
		commands = commands->next;
	}
	print_list(ms->commands);
	return (1);
}

void	fonction() // parsing
{
	if (parsing() == 1)
	{
		//printf("ta race\n");
	}
}