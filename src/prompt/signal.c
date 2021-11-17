/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:27 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 13:25:17 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit_process(int c)
{
	if (g_ms->fork)
		g_ms->end = 4;
	if (c == SIGQUIT)
	{
		if (g_ms->fork)
		{
			g_ms->status = 131;
			printf("Quit\n");
		}
		g_ms->fork = 0;
	}
	if (c == SIGINT)
	{
		printf("\n");
		if (g_ms->fork)
			g_ms->status = 130;
		else
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		g_ms->fork = 0;
	}
}
