/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:54:25 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/21 10:14:09 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*create_token3(char *s, int type)
{
	t_token	*tmp;

	tmp = ft_calloc(1, sizeof(t_token));
	tmp->word = ft_strdup(s);
	tmp->type = type;
	return (tmp);
}

static int	parse_token2(t_token **token, t_cmd *cmd)
{
	if ((*token)->type == TXT && (cmd->cmd || ((*token)->prev
				&& (*token)->prev->type == REDIR)))
		add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
	if ((*token)->type == TXT && !cmd->cmd && (((*token)->prev
				&& (*token)->prev->type != REDIR) || !(*token)->prev))
		cmd->cmd = ft_strdup((*token)->word);
	if ((*token)->type == REDIR)
		add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
	if ((*token)->type == EXIT_STATUS)
		add_token(&cmd->args, create_token3((*token)->word, (*token)->type));
	if ((*token)->type == ENV && !cmd->cmd)
	{
		cmd->cmd = ft_strdup((*token)->word);
		cmd->cmd = handle_quotes(cmd->cmd, 1);
	}
	if ((*token)->type == PIPE)
	{
		cmd->type = PIPE;
		*token = (*token)->next;
		return (0);
	}
	if ((*token)->type == POINT_V)
	{
		cmd->type = POINT_V;
		*token = (*token)->next;
		return (0);
	}
	return (1);
}

static void	add_list(t_cmd **begin, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new || !begin)
		return ;
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

	if ((*token)->type == NEWL)
	{
		*token = (*token)->next;
		return ;
	}
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return ;
	while (*token)
	{
		if (!parse_token2(token, cmd))
			break ;
		if ((*token)->type == ENV && cmd->cmd)
			add_token(&cmd->args, create_token3((*token)->word,
					(*token)->type));
		*token = (*token)->next;
	}
	add_list(&g_ms->cmds, cmd);
}

int	tokens_list_size(t_token *token)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
