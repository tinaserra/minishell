/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 13:13:51 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands_2(t_token *tmp2)
{
	while (g_ms->cmds->args)
	{
		tmp2 = g_ms->cmds->args->next;
		free(g_ms->cmds->args->word);
		free(g_ms->cmds->args);
		g_ms->cmds->args = tmp2;
	}
}

void	free_commands(void)
{
	t_cmd	*tmp;
	t_token	*tmp2;
	t_list	*tmp3;

	tmp2 = NULL;
	while (g_ms->cmds)
	{
		while (g_ms->cmds->env)
		{
			tmp3 = g_ms->cmds->env->next;
			free(g_ms->cmds->env);
			g_ms->cmds->env = tmp3;
		}
		free_commands_2(tmp2);
		ft_free_tab(g_ms->cmds->argss);
		tmp = g_ms->cmds->next;
		if (g_ms->cmds->cmd)
			free(g_ms->cmds->cmd);
		if (g_ms->cmds->bin)
			free(g_ms->cmds->bin);
		if (g_ms->cmds)
			free(g_ms->cmds);
		g_ms->cmds = tmp;
	}
}
