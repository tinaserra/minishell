/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:06:09 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/30 16:12:26 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_envv(char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (i == 0 && ft_isdigit(s[i]))
			return (0);
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
	}
	return (1);
}

void	unset_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	t_env	*env;
	int		pos;

	(void)cmd;
	tmp = cmd->args;
	if (tmp)
	{
		pos = lstfind_pos(g_ms->env, tmp->word);
		while (tmp)
		{
			if (is_valid_envv(tmp->word))
			{
				env = get_env2(g_ms->env, tmp->word);
				if (env)
				{
					env->show = 0;
					env->show2 = 0;
				}
			}
			else
				error("not a valid identifier", "unset", tmp->word, 1);
			tmp = tmp->next;
		}
	}
}
