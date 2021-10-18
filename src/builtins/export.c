/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:39:21 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/17 16:19:38 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_errors(char *res)
{
	int	i;

	i = -1;
	while (res[++i])
	{
		if (ft_strchr(" ,.%~@^*/", res[i]))
			return (1);
	}
	return (0);
}

void	export_builtin2(char **res)
{
	t_env	*tmp_env;

	tmp_env = get_env(g_ms->env, res[0]);
	if (tmp_env)
	{
		free(tmp_env->value);
		tmp_env->value = ft_strdup(res[1]);
	}
	else
		add_env(&g_ms->env, lst_new_env(ft_strdup(res[0]),
				ft_strdup(res[1])));
}

void	export_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	**res;

	tmp = cmd->args;
	while (tmp)
	{
		if (tmp && tmp->word)
		{
			res = ft_split(tmp->word, "=");
			if (res[0] && res[1])
			{
				if (!ft_isalpha(res[0][0]))
				{
					error("not a valid identifier", "export", tmp->word, 1);
					break ;
				}
				if (export_errors(res[0]))
					error("not a valid identifier", "export", tmp->word, 1);
				else
					export_builtin2(res);
			}
			ft_free_tab(res);
		}
		tmp = tmp->next;
	}
}
