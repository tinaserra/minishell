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

t_token	*redirect3(t_token *args, t_token **start)
{
	t_token	*tmp;
	t_token	*next;

	tmp = *start;
	if (*start == args)
	{
		next = (*start)->next;
		*start = next;
		if (next)
			next->prev = NULL;
		return (next);
	}
	while (tmp)
	{
		if (tmp == args && tmp->prev)
		{
			next = tmp->next;
			tmp->prev->next = next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			return (next);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int 	redirect2(t_cmd *cmd, t_token **args, int flags)
{
	int		fd;

	fd = open((*args)->next->word, flags, 0644);
	if (fd < 0)
		g_ms->exit = 1;
	if ((ft_strcmp((*args)->word, ">") == 0
			|| ft_strcmp((*args)->word, ">>") == 0) && cmd->out)
		close(cmd->out);
	if (ft_strcmp((*args)->word, "<") == 0 && cmd->in)
		close(cmd->in);
	*args = redirect3(*args, &cmd->args);
	*args = redirect3(*args, &cmd->args);
	return (fd);
}

void	redirect(t_cmd *cmd)
{
	t_token	*args;

	args = cmd->args;
	while (args && args->next)
	{
		if (ft_strcmp(args->word, ">") == 0 && args->type == 2
			&& cmd->out != -1)
			cmd->out = redirect2(cmd, &args, O_TRUNC | O_RDWR | O_CREAT);
		else if (ft_strcmp(args->word, ">>") == 0 && args->type == 2
			&& cmd->out != -1)
			cmd->out = redirect2(cmd, &args, O_RDWR | O_CREAT | O_APPEND);
		else if (ft_strcmp(args->word, "<") == 0 && args->type == 2
			&& cmd->in != -1)
			cmd->in = redirect2(cmd, &args, O_RDONLY);
		else
			args = args->next;
	}
}

void	exec_cmd(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		echo_builtin(cmd->args, cmd->out);
	if (ft_strcmp(cmd->cmd, "env") == 0)
		env_builtin(cmd->out);
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		cd_builtin(cmd);
	if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd_builtin();
}

void	exec_cmds(void)
{
	t_cmd	*cmd;

	cmd = g_ms->cmds;
	while (cmd)
	{
		//edit_args(cmd);
		redirect(cmd);
		exec_cmd(cmd);
		if (cmd->in)
			close(cmd->in);
		if (cmd->out)
			close(cmd->out);
		cmd = cmd->next;
	}
}

void	parsing(void)
{
	t_token	*tmp;

	split_minishell(g_ms->line);
	if (!get_token_type())
		ft_putstr_fd(1, "minishell: syntax error unexpected token\n");
	else
	{
		tmp = g_ms->tokens;
		while (tmp)
			parse_token(&tmp);
	}
	if (g_ms->cmds)
		exec_cmds();
	free_commands();
	free_token();
}
