/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/26 15:24:47 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void	clear(void *data)
{
	if (data)
		free(data);
}*/

void	free_commands(void)
{
	t_cmd	*tmp;
	t_token	*tmp2;
	t_list	*tmp3;

	while (g_ms->cmds)
	{
		while (g_ms->cmds->env)
		{
			tmp3 = g_ms->cmds->env->next;
			free(g_ms->cmds->env);
			g_ms->cmds->env = tmp3;
		}
		while (g_ms->cmds->args)
		{
			tmp2 = g_ms->cmds->args->next;
			free(g_ms->cmds->args->word);
			free(g_ms->cmds->args);
			g_ms->cmds->args = tmp2;
		}
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
