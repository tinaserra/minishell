/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:57:34 by admin             #+#    #+#             */
/*   Updated: 2021/10/02 12:50:17 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SUCCESS 0
#define FAILURE -1

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

int		exit_arg(char *arg, t_cmd *cmd)
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
				// return (FAILURE);
				// g_ms->status = nb % 256;
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
		printf("coucou\n");
		nb = ft_atoi(cmd->args->word);
		if (nb < 0 || nb > 255)
		{
			// error("numeric argument required", "exit", cmd->args->word, 2);
			printf("%d\n", nb);
		}
	}
	g_ms->status = nb % 256;
	free_all();
	// printf("love %d\n", nb);
	// g_ms->status = -95455562556515 % 256;
	// printf("status %d\n", g_ms->status);
	exit(nb);
}


// long long	atoi_exit(char *str)
// {
// 	int			i;
// 	long		sign;
// 	long long	nbr;

// 	i = 0;
// 	sign = 1;
// 	nbr = 0;
// 	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
// 		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ' || str[i] == '0')
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] && str[i] >= '0' && str[i] <= '9')
// 	{
// 		nbr = (nbr * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (nbr * sign);
// }

// int	get_exit_status(t_cmd *cmd)
// {
// 	int	nb;

// 	nb = 0;
// 	if (cmd->args)
// 	{
// 		if (str_is_digit(cmd->args->word))
// 		{
// 			nb = ft_atoi(cmd->args->word);
// 			if (nb < 0 || nb > 255)
// 				error("numeric argument required", "exit", cmd->args->word, 2);
// 		}
// 		else
// 			error("numeric argument required", "exit", cmd->args->word, 2);
// 	}
// 	return (nb);
// }
