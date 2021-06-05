#include "minishell.h"


int	split_ms(int i, char *s, char *chset, int type)
{
	if (type == 1 && is_in_str(chset, s[i]) && !is_in_str(chset, s[i + 1])
		&& !is_in_quote(s, i) && !is_escaped(s, i - 1))
		return (1);
	else if (!type && is_in_str(chset, s[i]) && i > 0
		&& is_in_str(chset, s[i - 1]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	else if (type == 2 && is_in_str(chset, s[i])
		&& i > 0 && is_in_str(chset, s[i - 1]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	else if (type == 3 && is_in_str(chset, s[i]) && !is_in_quote(s, i)
		&& !is_escaped(s, i - 1))
		return (1);
	return (0);
}

int	split_minishell2(char *s, int *i, t_token **start)
{
	if (is_in_str(" ", s[*i]) && !is_in_quote(s, *i)
		&& !is_escaped(s, *i - 1))
	{
		add_token(start, create_token(*i));
		(*i)++;
		return (0);
	}
	if (is_in_str(";|<>", s[*i]) && !is_in_quote(s, *i)
		&& !is_escaped(s, *i - 1) && *i > 0 && !is_in_str("<>", s[*i - 1]))
		add_token(start, create_token(*i));
	return (1);
}

void	split_minishell(char *cmd)
{
	int		i;
	t_token	**start;

	i = 0;
	start = &g_ms->tokens;
	while (cmd[i])
	{
		if (!split_minishell2(cmd, &i, start))
			continue ;
		g_ms->count++;
		if (split_ms(i, cmd, ";|", 3) || split_ms(i, cmd, ">", 1)
			|| split_ms(i, cmd, ">", 0) || split_ms(i, cmd, "<", 1)
			|| split_ms(i, cmd, "<", 0))
			add_token(start, create_token(i + 1));
		i++;
	}
	if (i > 0)
	{
		add_token(&g_ms->tokens, create_token(i));
		add_token(&g_ms->tokens, create_token2("\n", i));
	}
}

void	parsing()
{
	split_minishell(g_ms->line);
	if (!get_token_type())
		ft_putstr_fd(1, "minishell: syntax error unexpected token\n");
	else
	{
		while (g_ms->tokens)
		{
			printf("[%d]  [%s]\n", g_ms->tokens->type, g_ms->tokens->word);
			g_ms->tokens = g_ms->tokens->next;
		}
	}
	free_token();
	
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
