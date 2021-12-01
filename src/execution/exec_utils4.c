/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:55:26 by jode-vri          #+#    #+#             */
/*   Updated: 2021/12/01 15:40:30 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lstcreate(char *data, t_token *next)
{
	t_token	*cell;

	cell = malloc(sizeof(t_token));
	if (cell == NULL)
		return (NULL);
	cell->word = ft_strdup(data);
	cell->type = 5;
	cell->next = next;
	return (cell);
}

void	test(t_cmd *cmd)
{
	char	**res;
	t_token	*tmp;
	t_token	*tmp2;

	if (is_in_str(cmd->cmd, ' '))
	{
		res = ft_split(cmd->cmd, " ");
		free(cmd->cmd);
		cmd->cmd = ft_strdup(res[0]);
		if (cmd->args)
		{
			tmp = cmd->args->next;
			while (cmd->args)
			{
				tmp2 = cmd->args->next;
				free(cmd->args->word);
				free(cmd->args);
				cmd->args = tmp2;
			}
			cmd->args = lstcreate(res[1], tmp);
		}
		free(cmd->bin);
		free(cmd->cmd);
		cmd->cmd = ft_strdup(res[0]);
		ft_free_tab(res);
	}
}
