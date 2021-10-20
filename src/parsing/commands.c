/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/20 11:10:46 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands(void)
{
	t_cmd	*tmp;
	t_token	*tmp2;

	while (g_ms->cmds)
	{
		/*printf("%d\n", g_ms->cmds->argss ? 1 : 0);
		if (g_ms->cmds->argss)
			ft_free_tab(g_ms->cmds->argss);*/
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
		if (g_ms->cmds->bin)	
			free(g_ms->cmds->bin);
		if (g_ms->cmds)
			free(g_ms->cmds);
		g_ms->cmds = tmp;
	}
}
