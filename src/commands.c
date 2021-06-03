/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:30:56 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/03 01:31:36 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands(void)
{
	t_list	*tmp;

	while (ms->commands)
	{
		tmp = ms->commands->next;
		free(ms->commands->data);
		free(ms->commands);
		ms->commands = tmp;
	}
}