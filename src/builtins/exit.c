/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:57:34 by admin             #+#    #+#             */
/*   Updated: 2021/09/22 01:21:44 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int str_is_digit(char *s)
{
	int i;

	i = 0;
	printf("[%d]\n", ft_isdigit(s[0]));
	if (s[0] != '-' || !ft_isdigit(s[0]))
	{
		printf("a\n");
		return (0);
	}
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
		printf("b\n");
			return (0);
		}
	}
	return (1);
}

int	get_exit_status(t_cmd *cmd)
{
	int status;
	int	nb;

	status = 0;
	if (cmd->args)
	{
		if (str_is_digit(cmd->args->word))
		{
			nb = ft_atoi(cmd->args->word);
			if (nb > INT_MAX || nb < INT_MIN)
				printf("minishell: exit: %s: wrong argument\n", cmd->args->word);
		}
		else
			printf("minishell: exit: %s: wrong argument 1\n", cmd->args->word);
	}
	return (status);
}

void	exit_builtin(t_cmd *cmd)
{
	int	status;

	status = 0;
	printf("exit\n");
	if (tokens_list_size(cmd->args) > 1)
	{
		printf("minishell: exit: too many arguments\n");
		return ;
	}
	status = get_exit_status(cmd);
	// free all
	exit(status);
}