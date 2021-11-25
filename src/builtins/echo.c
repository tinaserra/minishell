/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:21:24 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 12:58:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define OPT_N 0
#define NL 1

static int	echo_new_line(char *s)
{
	int	i;

	i = 0;
	if (s[i] && s[i] == '-' && s[i + 1] && s[i + 1] == 'n')
	{
		i += 2;
		while (s[i] && s[i] == 'n')
			i++;
		if (s[i] && s[i] != 'n')
			return (NL);
		g_ms->newline = OPT_N;
		return (OPT_N);
	}
	return (NL);
}

static int	echo_tmp_check(t_token	*tmp, int fd)
{
	if (!tmp)
	{
		ft_putchar_fd('\n', fd);
		return (-1);
	}
	if (echo_new_line(tmp->word) == OPT_N && !tmp->next)
		return (-1);
	return (0);
}

static int	loop_nl(t_token	*tmp)
{
	g_ms->newline = OPT_N;
	if (!tmp->next)
		return (-1);
	return (0);
}

void	echo_builtin(t_cmd *cmd, int fd)
{
	t_token	*tmp;

	tmp = cmd->args;
	if (fd == 0)
		fd = STDOUT_FILENO;
	if (ft_strcmp(cmd->cmd, tmp->word) == 0)
		tmp = tmp->next;
	if (echo_tmp_check(tmp, fd) == -1)
		return ;
	g_ms->newline = NL;
	while (echo_new_line(tmp->word) == OPT_N)
	{
		if (loop_nl(tmp) == -1)
			return ;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (!ft_strcmp(tmp->word, "~"))
		{
			ft_putstr_fd(get_env(g_ms->env, "HOME")->value, fd);
			tmp = tmp->next;
		}
		if (tmp)
		{
			if (tmp->type == EXIT_STATUS)
				ft_putnbr_fd(g_ms->status, STDOUT_FILENO);
			ft_putstr_fd(tmp->word, fd);
		}
		if (tmp && tmp->next)
			ft_putchar_fd(' ', fd);
		else if (g_ms->newline == NL)
			ft_putchar_fd('\n', fd);
		if (tmp)
			tmp = tmp->next;
	}
}
