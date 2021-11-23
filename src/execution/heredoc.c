/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:51:46 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 13:09:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_2(char *tmp, int fd[2])
{
	free(tmp);
	if (!g_ms->hd_quit)
		ft_putstr_fd(g_ms->hd_line, fd[1]);
	free(g_ms->hd_line);
	close(fd[1]);
	rl_getc_function = g_ms->getc_func;
	signal(SIGINT, quit_process);
	signal(SIGQUIT, quit_process);
}

int	gettc(FILE *file)
{
	int	c;

	c = getc(file);
	if (c == -1 && g_ms->hd_start == 1)
	{
		g_ms->hd_quit = 1;
		rl_done = 1;
	}
	return (c);
}

void	heredoc2(char *tmp, t_token **token)
{
	if (tmp && ft_strcmp((*token)->next->word, tmp) != 0)
	{
		if (ft_strcmp(tmp, "$?") == 0)
			tmp = ft_itoa(g_ms->status);
		else if (is_in_str(tmp, '$'))
			tmp = replace_env(tmp, ft_find_in_str(tmp, '$'));
		g_ms->hd_line = ft_strjoin_free(g_ms->hd_line, tmp, 'L');
		g_ms->hd_line = ft_strjoin_free(g_ms->hd_line, "\n", 'L');
	}
}

void	heredoc(t_cmd *cmd, t_token **token)
{
	char	*tmp;
	int		fd[2];

	pipe(fd);
	cmd->in = fd[0];
	tmp = NULL;
	(*token)->next->word = handle_quotes((*token)->next->word, 0);
	g_ms->hd_quit = 0;
	g_ms->hd_start = 1;
	g_ms->fork = 0;
	g_ms->hd_line = ft_strdup("");
	while (g_ms->hd_quit == 0
		&& (!tmp || ft_strcmp((*token)->next->word, tmp) != 0))
	{
		free(tmp);
		signal(SIGINT, hd_signal);
		signal(SIGQUIT, hd_signal);
		rl_getc_function = gettc;
		tmp = readline("> ");
		if (!tmp || g_ms->hd_quit != 0)
			break ;
		heredoc2(tmp, token);
	}
	hd_2(tmp, fd);
}
