/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:58:21 by vserra            #+#    #+#             */
/*   Updated: 2021/11/11 14:55:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SUCCESS 0
#define FAILURE -1

static void exit_error(char *word)
{
	error("numeric argument required", "exit", word, 2);
	g_ms->status = 2;
	free_all();
	exit(2);
}

static double long	exit_arg(char *arg, t_cmd *cmd)
{
	int		i;
	int 	len;

	i = 0;
	len = ft_strlen(arg);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!((arg[i] >= '\t' && arg[i] <= '\r') || arg[i] == ' '))
		{
			if (arg[i] < '0' || arg[i] > '9')
				exit_error(cmd->args->word);
		}
		i++;
	}
	return (SUCCESS);
}

void	exit_builtin(t_cmd *cmd)
{
	double long	nb;

	nb = 0;
	if (!(cmd->prev && cmd->prev->type == PIPE))
		printf("exit\n");
	if (cmd->args && exit_arg(cmd->args->word, cmd) == FAILURE)
		return ;
	if (tokens_list_size(cmd->args) > 1)
	{
		error("too many arguments", "exit", NULL, 1);
		return ;
	}
	if (cmd->args && exit_arg(cmd->args->word, cmd) == SUCCESS)
	{
		nb = ft_atoi(cmd->args->word);
		if (nb < LONG_MIN || nb > LONG_MAX)
			exit_error(cmd->args->word);
	}
	g_ms->status = (int)nb % 256;
	free_all();
	exit(nb);
}
