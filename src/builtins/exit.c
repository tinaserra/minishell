/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:58:21 by vserra            #+#    #+#             */
/*   Updated: 2021/10/13 14:08:58 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SUCCESS 0
#define FAILURE -1

static int	exit_arg(char *arg, t_cmd *cmd)
{
	int		i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!((arg[i] >= '\t' && arg[i] <= '\r') || arg[i] == ' '))
		{
			if (arg[i] < '0' || arg[i] > '9')
			{
				error("numeric argument required", "exit", cmd->args->word, 2);
				g_ms->status = 2;
				free_all();
				exit(2);
			}
		}
		i++;
	}
	return (SUCCESS);
}

void	exit_builtin(t_cmd *cmd)
{
	int	nb;

	nb = 0;
	printf("exit\n");
	if (tokens_list_size(cmd->args) > 1)
	{
		error("too many arguments", "exit", cmd->args->word, 1);
		return ;
	}
	if (cmd->args && exit_arg(cmd->args->word, cmd) == SUCCESS)
	{
		nb = ft_atoi(cmd->args->word);
		if (nb < 0 || nb > 255)
			printf("%d : superieur a 255 ou  inferieur a 0\n", nb);
	}
	g_ms->status = nb % 256;
	free_all();
	exit(nb);
}
