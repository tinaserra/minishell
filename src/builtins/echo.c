/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:21:24 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/13 13:30:19 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define OPT_N 0
#define NL 1

int	echo_new_line(char *s)
{
	int i;

	i = 0;
	if (s[i] && s[i] == '-' && s[i + 1] && s[i + 1] == 'n')
	{
		i += 2;
		while (s[i] && s[i] == 'n')
			i++;
		if (s[i] && s[i] != 'n')
			return (NL);
		g_ms->newline = 0;
		return (OPT_N);
	}
	return (NL);
}

void	echo_builtin(t_token *args, int fd)
{
	t_token	*tmp;

	tmp = args;
	if (fd == 0)
		fd = 1;
	if (!tmp)
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	g_ms->newline = NL;
	while (tmp)
	{
		while (echo_new_line(tmp->word) == OPT_N)
		{
			g_ms->newline = OPT_N;
			tmp = tmp->next;
		}
		if (tmp->type == EXIT_STATUS)
			ft_putnbr_fd(g_ms->status, STDOUT_FILENO);
		ft_putstr_fd(tmp->word, fd);
		if (tmp->next)
			ft_putchar_fd(' ', fd);
		else if (g_ms->newline == NL)
			ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
