/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:57:34 by admin             #+#    #+#             */
/*   Updated: 2021/10/01 08:25:44 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_is_digit(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-' || !ft_isdigit(s[0]))
		return (0);
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

int	get_exit_status(t_cmd *cmd)
{
	int	status;
	int	nb;

	status = 0;
	if (cmd->args)
	{
		if (str_is_digit(cmd->args->word))
		{
			nb = ft_atoi(cmd->args->word);
			if (nb > INT_MAX || nb < INT_MIN)
				print_error("numeric argument required", "exit", cmd->args->word, 2);
				// printf("minishell: exit: %s: wrong argument\n", cmd->args->word);
		}
		else
			printf("minishell: exit: %s: wrong argument\n", cmd->args->word);
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
	free_all();
	exit(status);
}
