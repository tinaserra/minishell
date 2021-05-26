#include "minishell.h"

void	print_list(t_list *l)
{
	if (l == NULL)
		printf("la liste est vide\n");
	while (l != NULL)
	{
		printf("[%s]\n", (char *)l->data);
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
			ft_putstr_fd(2, "syntax error near unexpected token `;;`\n");
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

	// if ((mask & DOUBLE_Q) == 1) ->  y a "
	// if (mask == DOUBLE_Q) ->  y a " uniquement

int		truc(char *s)
{
	printf("fdp (s) = %d\n", ms->fdp);
	// i = 0;
	ms->mask = 0;
	while (s[ms->fdp])
	{
		if (s[ms->fdp] == '\'' && ms->mask == 0)
			ms->mask ^= SIMPLE_Q;
		if (s[ms->fdp] == '"' && ms->mask == 0) // && ms->mask == 0
			ms->mask ^= DOUBLE_Q;
		if (ms->mask == DOUBLE_Q)
		{
			ms->fdp++;
			while (s[ms->fdp] != '"')
			{
				if (s[ms->fdp] == '$')
				{
					printf("fdp (e) = %d\n", ms->fdp);
					printf("char =    %c\n", s[ms->fdp]);
					return (ms->mask);
				}
				ms->fdp++;
			}
			if (s[ms->fdp] == '"')
				ms->mask = 0;
		}
		else if (ms->mask == SIMPLE_Q)
		{
			ms->fdp++;
			while (s[ms->fdp] != '\'')
			{
				if (s[ms->fdp] == '$')
				{
					printf("fdp (e) = %d\n", ms->fdp);
					printf("char =    %c\n", s[ms->fdp]);
					return (ms->mask);
				}
				ms->fdp++;
			}
			if (s[ms->fdp] == '\'')
				ms->mask = 0;
		}
		ms->fdp++;
	}
	printf("fdp (e) = %d\n", ms->fdp);
	printf("char =    %c\n", s[ms->fdp]);
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
	ms->fdp = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (truc(str) != SIMPLE_Q) //
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
	// ici on split les commandes sur le ;
	i = 0;
	old = 0;
	ms->mask = 0;
	while (ms->line[i] != '\0')
	{
		if (ms->line[i] == '"')
			ms->mask ^= DOUBLE_Q;
		if (ms->line[i] == '\'')
			ms->mask ^= SIMPLE_Q;
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