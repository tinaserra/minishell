/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:56:58 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 13:53:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*checkk(t_token **start, t_token *args, t_token *next)
{
	if (*start == args)
	{
		next = (*start)->next;
		free((*start)->word);
		free(*start);
		*start = next;
		if (next)
			next->prev = NULL;
		return (next);
	}
	return (NULL);
}

t_token	*redirect3(t_token *args, t_token **start)
{
	t_token	*tmp;
	t_token	*next;
	t_token	*tmp2;

	tmp = *start;
	next = NULL;
	tmp2 = checkk(start, args, next);
	if (tmp2)
		return (tmp2);
	while (tmp)
	{
		if (tmp == args && tmp->prev)
		{
			next = tmp->next;
			tmp->prev->next = next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(args->word);
			free(args);
			return (next);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	close_fds(t_cmd *cmd, t_token **args)
{
	if ((ft_strcmp((*args)->word, ">") == 0
			|| ft_strcmp((*args)->word, ">>") == 0) && cmd->out > 0)
		close(cmd->out);
	if (ft_strcmp((*args)->word, "<") == 0 && cmd->in > 0)
		close(cmd->in);
}

int	redirect2(t_cmd *cmd, t_token **args, int flags)
{
	int		fd;
	char	*tmp;

	tmp = find_binary(cmd, 0);
	if (!tmp)
	{
		free(tmp);
		error("command not found", cmd->cmd, NULL, 127);
		return (-1);
	}
	free(tmp);
	fd = open((*args)->next->word, flags, 0644);
	if (fd < 0)
	{
		if (!ft_strcmp((*args)->next->word, ""))
			error("ambiguous redirect", NULL, NULL, -1);
		else
			error("No such file or directory", (*args)->next->word, NULL, 1);
		return (-1);
	}
	close_fds(cmd, args);
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
		else if (ft_strcmp(args->word, "<<") == 0 && args->type == REDIR)
		{
			heredoc(cmd, &args);
			args = redirect3(args, &cmd->args);
			args = redirect3(args, &cmd->args);
		}
		else
			args = args->next;
	}
}
