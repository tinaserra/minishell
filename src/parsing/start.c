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

void	edit_args(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	while (tmp)
	{
		
		tmp = tmp->next;
	}
}

void	exec_cmds()
{
	t_cmd	*cmd;

	cmd = g_ms->cmds;
	while (cmd)
	{
		edit_args(cmd);
		cmd = cmd->next;
	}
}

void	parsing()
{
	t_token	*tmp;
	//t_cmd	*tmp2;
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
	/*tmp2 = g_ms->cmds;
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
	}*/
	if (g_ms->cmds)
		execute_cmd();
	free_commands();
	free_token();
}
