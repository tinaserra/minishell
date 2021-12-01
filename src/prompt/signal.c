/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:27 by jode-vri          #+#    #+#             */
/*   Updated: 2021/12/01 14:35:32 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit_process2(void)
{
	if (g_ms->fork)
		g_ms->status = 130;
	else if (g_ms->fork && g_ms->hd_start)
	{
		g_ms->hd_start = 0;
		g_ms->fork = 0;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	quit_process(int c)
{
	g_ms->line = NULL;
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
		quit_process2();
		g_ms->fork = 0;
	}
}

void	hd_signal(int c)
{
	(void)c;
	printf("\n");
}
