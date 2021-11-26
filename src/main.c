/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:56:37 by vserra            #+#    #+#             */
/*   Updated: 2021/11/11 13:06:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(void)
{
	free_env();
	free_commands();
	if (g_ms->hd_tmp)
		free(g_ms->hd_tmp);
	if (g_ms->line)
		free(g_ms->line);
	if (g_ms->term)
		free(g_ms->term);
	if (g_ms->curdir)
		free(g_ms->curdir);
	if (g_ms)
		free(g_ms);
}

void	init(char **env)
{
	g_ms = malloc(sizeof(t_minishell));
	ft_bzero(g_ms, sizeof(t_minishell));
	g_ms->curdir = getcwd(NULL, 0);
	g_ms->getc_func = rl_getc_function;
	signal(SIGINT, quit_process);
	signal(SIGQUIT, quit_process);
	if (!init_env(env))
		exit(EXIT_FAILURE);
	rl_getc_function = g_ms->getc_func;
	g_ms->term = print_prompt();
	g_ms->line = readline(g_ms->term);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	init(env);
	while (g_ms->line != NULL)
	{
		g_ms->fork = 0;
		g_ms->end = 0;
		signal(SIGINT, quit_process);
		signal(SIGQUIT, quit_process);
		if (g_ms->line && ft_strcmp(g_ms->line, "") != 0)
		{
			add_history(g_ms->line);
			parsing();
		}
		free(g_ms->line);
		g_ms->line = NULL;
		g_ms->line = readline(g_ms->term);
	}
	printf("exit");
	free_all();
}
