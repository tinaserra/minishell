/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:27 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/08 09:38:04 by jode-vri         ###   ########.fr       */
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
			g_ms->exit = 131;
			printf("Quit\n");
		}
		g_ms->fork = 0;
	}
	if (c == SIGINT)
	{
		printf("\n");
		if (g_ms->fork)
			g_ms->exit = 130;
		else
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		g_ms->fork = 0;
	}
}