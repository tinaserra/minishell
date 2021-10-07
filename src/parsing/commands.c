/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/07 12:00:21 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands(void)
{
	t_cmd	*tmp;
	t_token	*tmp2;

	while (g_ms->cmds)
	{
		while (g_ms->cmds->args)
		{
			tmp2 = g_ms->cmds->args->next;
			free(g_ms->cmds->args->word);
			free(g_ms->cmds->args);
			g_ms->cmds->args = tmp2;
		}
		tmp = g_ms->cmds->next;
		if (g_ms->cmds->cmd)	
			free(g_ms->cmds->cmd);
		free(g_ms->cmds);
		g_ms->cmds = tmp;
	}
}
