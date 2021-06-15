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

t_token		*create_token3(char *s, int type)
{
	t_token	*tmp;

	tmp = ft_calloc(1, sizeof(t_token));
	tmp->word = ft_strdup(s);
	tmp->type = type;
	return (tmp);
}

int	parse_token2(t_token **token, t_cmd *cmd)
{
	if ((*token)->type == 5 && (cmd->cmd || ((*token)->prev
		&& (*token)->prev->type == 2)))
		add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
	if ((*token)->type == 5 && !cmd->cmd && (((*token)->prev
		&& (*token)->prev->type != 2) || !(*token)->prev))
		cmd->cmd = ft_strdup((*token)->word);
	if ((*token)->type == 2)
		add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
	if ((*token)->type == 3 && !cmd->cmd)
		ft_lstadd_back(&cmd->env, ft_lstcreate(ft_strdup((*token)->word)));
	if ((*token)->type == 1)
	{
		cmd->type = 1;
		*token = (*token)->next;
		return (0);
	}
	if ((*token)->type == 0)
	{
		cmd->type = 0;
		*token = (*token)->next;
		return (0);
	}
	return (1);
}

void	add_list(t_cmd **begin, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new || !begin)
		return ;
	//
	if (*begin)
	{
		tmp = *begin;
		while (tmp->next)
		{
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
		*begin = new;
}

void	parse_token(t_token	**token)
{
	t_cmd	*cmd;

	if ((*token)->type == 4)
	{
		*token = (*token)->next;
		return ;
	}
	if (!(cmd = ft_calloc(1, sizeof(t_cmd))))
		return ;
	while (*token)
	{
		if (!parse_token2(token, cmd))
			break ;
		if((*token)->type == 3 && cmd->cmd)
			add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
		*token = (*token)->next;
	}
	add_list(&g_ms->cmds, cmd);
}

void	parsing()
{
	t_token	*tmp;
	t_cmd	*tmp2;
	t_token	*i;

	split_minishell(g_ms->line);
	if (!get_token_type())
		ft_putstr_fd(1, "minishell: syntax error unexpected token\n");
	else
	{
		tmp = g_ms->tokens;
		while (tmp)
			parse_token(&tmp);
	}
	tmp2 = g_ms->cmds;
	while (tmp2)
	{
		i = tmp2->args;
		printf("command: %s\n", tmp2->cmd);
		while (i)
		{
			printf("\targ: [%d] %s\n", i->type, i->word);
			i = i->next;
		}
		tmp2 = tmp2->next;
	}

	free_commands();
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
