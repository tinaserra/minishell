/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/04 23:18:14 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands(void)
{
	t_list	*tmp;

	while (g_ms->commands)
	{
		tmp = g_ms->commands->next;
		free(g_ms->commands->data);
		free(g_ms->commands);
		g_ms->commands = tmp;
	}
}