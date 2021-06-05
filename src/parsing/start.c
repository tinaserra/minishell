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

	// if (str[i] == '"' && !(g_ms->mask & SIMPLE_Q))// on une double quote en premier

int	check_syntaxe(void)
{
	int		i;

	g_ms->mask = 0;
	i = 0;
	while (g_ms->line[i])
	{
		if (g_ms->line[i] == ';' && g_ms->line[i + 1] == ';')
		{	
			ft_putstr_fd(2, "syntax error near unexpected token `;;`\n");
			return (0);
		}
		i++;
	}
	return (1);
}
//str[*(i - 1)] != '\\' 
void	check_quotes(char *str, int *i)
{
	if (g_ms->quote == 0)
	{
		if ((str[*i - 1] != '\\' && i != 0) && str[*i] == '\'')
		{
			g_ms->quote = '\'';
			(*i)++;
		}
		if ((str[*i - 1] != '\\' && i != 0) && str[*i] == '"')
		{
			g_ms->quote = '"';
			(*i)++;
		}
		
	}
	if ((str[*i - 1] != '\\' && i != 0) && str[*i] == '\'' && g_ms->quote == '\'')
		g_ms->quote = 0;
	if ((str[*i - 1] != '\\' && i != 0) && str[*i] == '"' && g_ms->quote == '"')
		g_ms->quote = 0;
}

char	*handle_env(char *str)
{
	int	i;

	i = 0;
	g_ms->quote = 0;
	while (str[i])
	{
		check_quotes(str, &i);
		if (str[i] == '$')
		{
			if (g_ms->quote != '\'')
				str = replace_env(str, i);
		}
		i++;
	}
	return (str);
}

t_list	*split_pointvirgule(void)
{
	int		i;
	int		old;
	char	*tmp;
	t_list	*commands;

	i = 0;
	old = 0;
	commands = NULL;
	while (g_ms->line[i] != '\0')
	{
		check_quotes(g_ms->line, &i);
		if ((g_ms->line[i] == ';' || g_ms->line[i + 1] == '\0') && g_ms->quote == 0) // /!\ ne rempli pas en cas de quote non fermees
		{
			if (g_ms->line[i + 1] == '\0' && g_ms->line[i] != ';')
				tmp = ft_substr(g_ms->line, old, i - old + 1);
			else
				tmp = ft_substr(g_ms->line, old, i - old);
			tmp = ft_strtrim(tmp, "\f\t\n\r\v ");
			ft_lstadd_back(&commands, ft_lstcreate(tmp));
			old = i + 1;
		}
		i++;
	}
	return (commands);
}

void	parsing()
{
	split_minishell(g_ms->line);
	get_token_type();
	while (g_ms->tokens)
	{
		printf("[%d]  [%s]\n", g_ms->tokens->type, g_ms->tokens->word);
		g_ms->tokens = g_ms->tokens->next;
	}
	//t_list	*commands;

	//g_ms->quote = 0;
	//g_ms->line = ft_strtrim(g_ms->line, "\f\t\n\r\v ");
	//if (check_syntaxe() == 0)
	//	return ;
	//g_ms->commands = split_pointvirgule();
	//commands = g_ms->commands;
	//while (commands)
	//{
	//	commands->data = handle_env(commands->data);
	//	// stocker commandes et arguments dans un tableau
	//	split_minishell((char *)commands->data);
	//	// lancer les builtins & edecuter
	//	commands = commands->next;
	//}
	////ft_lstprint(g_ms->commands);
}
