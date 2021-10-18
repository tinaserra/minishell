/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:27 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/18 12:57:31 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int c)
{
	if (c == SIGINT)
		return ;
	if (c == SIGINT && g_ms->fork)
		printf("Quit\n");
	if (c == SIGQUIT && g_ms->fork)
		printf("\n");
	if (c == SIGQUIT && !g_ms->fork)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	quit_process(int c)
{
	if (c == SIGINT)
		printf("Quit: %d\n", c);
	g_ms->end = 4;
	if (c == SIGQUIT)
		g_ms->exit = 131;
	if (c == SIGINT)
	{
		g_ms->exit = 130;
		printf("\n");
	}
}