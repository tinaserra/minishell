/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:06:09 by jode-vri          #+#    #+#             */
/*   Updated: 2021/09/15 11:39:21 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_builtin(t_cmd *cmd)
{
	(void)cmd;
	t_token	*tmp;
	t_env	*tmp_env;

	tmp = cmd->args;
	while (tmp)
	{
		if (tmp && tmp->word)
		{
			tmp_env = get_env2(g_ms->env, tmp->word);
			printf("prev: %s\n", tmp_env->name);
		}
		tmp = tmp->next;
	}
}