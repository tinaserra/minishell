#include "minishell.h"

	// AND &
	// 0 & 0 = 0
	// 0 & 1 = 0
	// 1 & 0 = 0
	// 1 & 1 = 1

	// if ((mask & DOUBLE_Q) == 1) ->  y a "
	// if (mask == DOUBLE_Q) ->  y a " uniquement


	// 					 0000 0001 & 0000 0010
	// savoir si une chaine est entre simple quote ou double quote

	// "......'$HOME'"	-> contenu
	// "..'..." '$HOME'	-> $HOME
	// "......'" $HOME	-> contenu
	// '......"$HOME"'	-> $HOME

	// "......'$HOME'" ; "..'..." '$HOME' ; "......'" $HOME ; '......"$HOME"'

	// parcoure la chaine et si " la plus grosse boite c'est " si le $ et dedans

	// if (str[i] == '"' && !(ms->mask & SIMPLE_Q))// on une double quote en premier

int	check_syntaxe(void)
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

void	check_quotes(char *str, int *i)
{
	if (str[*i] == '\'' && ms->quote == 0)
	{
		ms->quote = '\'';
		(*i)++;
	}
	if (str[*i] == '"' && ms->quote == 0)
	{
		ms->quote = '"';
		(*i)++;
	}
	if (str[*i] == '\'' && ms->quote == '\'')
		ms->quote = 0;
	if (str[*i] == '"' && ms->quote == '"')
		ms->quote = 0;
}

char	*truc(char *str)
{
	int	i;

	i = 0;
	ms->quote = 0;
	while (str[i])
	{
		check_quotes(str, &i);
		if (str[i] == '$')
		{
			if (ms->quote != '\'')
				str = replace_env(str, i);
		}
		i++;
	}
	return (str);
}

t_list	*parsing(void)
{
	int		i;
	int		old;
	char	*tmp;
	t_list	*commands;

	i = 0;
	old = 0;
	commands = NULL;
	while (ms->line[i] != '\0')
	{
		check_quotes(ms->line, &i);
		if ((ms->line[i] == ';' || ms->line[i + 1] == '\0') && ms->quote == 0)
		{
				if (ms->line[i + 1] == '\0' && ms->line[i] != ';')
					tmp = ft_substr(ms->line, old, i - old + 1);
				else
					tmp = ft_substr(ms->line, old, i - old);
				tmp = ft_strtrim(tmp, "\f\t\n\r\v ");
				ft_lstadd_back(&commands, ft_lstcreate(tmp));
				old = i + 1;
		}
		i++;
	}
	return (commands);
}

void	fonction(void)
{
	t_list	*commands;

	ms->quote = 0;
	ms->line = ft_strtrim(ms->line, "\f\t\n\r\v ");
	if (check_syntaxe() == 0)
		return ;
	ms->commands = parsing();
	commands = ms->commands;
	while (commands)
	{
		commands->data = truc(commands->data);
		commands = commands->next;
	}
	ft_lstprint(ms->commands);
}
