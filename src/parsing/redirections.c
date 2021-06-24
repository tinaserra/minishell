#include "minishell.h"

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
		if (ft_strcmp(args->word, ">") == 0 && args->type == REDIR
			&& cmd->out != -1)
			cmd->out = redirect2(cmd, &args, O_TRUNC | O_RDWR | O_CREAT);
		else if (ft_strcmp(args->word, ">>") == 0 && args->type == REDIR
			&& cmd->out != -1)
			cmd->out = redirect2(cmd, &args, O_RDWR | O_CREAT | O_APPEND);
		else if (ft_strcmp(args->word, "<") == 0 && args->type == REDIR
			&& cmd->in != -1)
			cmd->in = redirect2(cmd, &args, O_RDONLY);
		else
			args = args->next;
	}
}
