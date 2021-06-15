#include "minishell.h"

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