/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:12:13 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/01 08:13:27 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** The following symbolic constants shall be defined for file streams:
**
** STDERR_FILENO
** 		File number of stderr; 2.
** STDIN_FILENO
** 		File number of stdin; 0.
** STDOUT_FILENO
** 		File number of stdout; 1.
*/

void	print_error(char *message, char *cmd, char *arg, int status)
{
	if (status > 0)
		g_ms->status = status;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	if (cmd)
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
