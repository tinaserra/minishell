/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:08:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/04/13 04:16:43 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    env_builtin()
{
    int     i;
    t_env   *tmp;

    i = -1;
    tmp = ms->env;
    while (tmp)
    {
        ft_putstr_fd(1, tmp->name);
        ft_putchar_fd('=', 1);
        ft_putstr_fd(1, tmp->value);
        ft_putchar_fd('\n', 1);
        tmp = tmp->next;
    }
}