/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:39:21 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/08 11:15:32 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_errors(char *res)
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

void	export_builtin2(char **identifier, char *content)
{
	t_env	*tmp_env;

	tmp_env = get_env(g_ms->env, identifier[0]);
	if (tmp_env)
	{
		free(tmp_env->value);
		tmp_env->value = ft_strdup(content);
	}
	else
		add_env(&g_ms->env, lst_new_env(ft_strdup(identifier[0]),
				ft_strdup(content)));
}

void	export_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	*content;
	char	**identifier;

	tmp = cmd->args;
	while (tmp)
	{
		if (tmp && tmp->word)
		{
			identifier = ft_split(tmp->word, "=");
			content = ft_strchr(tmp->word, '=');
			
			if (identifier[0] && content && content[0] == '=')
			{
				if (content && ft_strcmp(content, "") != 0)
				{
					content++;
					if (!ft_isalpha(identifier[0][0]) && identifier[0][0] != '_')
					{
						error("not a valid identifier", "export", tmp->word, 1);
						break ;
					}
					if (export_errors(identifier[0]))
						error("not a valid identifier", "export", tmp->word, 1);
					else
						export_builtin2(identifier, content);
				}
				else
					error("not a valid identifier", "export", tmp->word, 1);
			}
			ft_free_tab(identifier);
		}
		tmp = tmp->next;
	}
}
