/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:21:24 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/01 08:21:25 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_new_line(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (0);
	return (1);
}

void	echo_builtin(t_token *args, int fd)
{
	int		nl;
	t_token	*tmp;

	tmp = args;
	if (fd == 0)
		fd = 1;
	if (!tmp)
		return ;
	nl = echo_new_line(tmp->word);
	if (nl == 0)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == EXIT_STATUS)
			ft_putnbr_fd(g_ms->status, STDOUT_FILENO);
		ft_putstr_fd(tmp->word, fd);
		if (tmp->next)
			ft_putchar_fd(' ', fd);
		else if (nl)
			ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
