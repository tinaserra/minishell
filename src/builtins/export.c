/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:39:21 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/12 14:43:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_errors(char *res)
{
	int	i;

	i = -1;
	while (res[++i])
	{
		if (ft_strchr(" ,.%~@!\\|;&'$\"^*/", res[i]))
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

int	export_2(t_token *tmp, char **id, char *content)
{
	content++;
	if (!ft_isalpha(id[0][0]) && id[0][0] != '_')
	{
		error("not a valid identifier", "export", tmp->word, 1);
		return (0);
	}
	if (export_errors(id[0]))
		error("not a valid identifier", "export", tmp->word, 1);
	else
		export_builtin2(id, content);
	return (1);
}

void	exportt(t_token *tmp, char *content)
{
	char	**id;

	while (tmp)
	{
		if (tmp && tmp->word)
		{
			content = ft_strchr(tmp->word, '=');
			if (content)
			{
				id = ft_split(tmp->word, "=");
				if (id[0] && content && content[0] == '=')
				{
					if (content && ft_strcmp(content, "") != 0)
					{
						if (!export_2(tmp, id, content))
							break ;
					}
					else
						error("not a valid identifier", "export", tmp->word, 1);
				}
				ft_free_tab(id);
			}
		}
		tmp = tmp->next;
	}
}

void	export_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	*content;

	tmp = cmd->args;
	content = NULL;
	exportt(tmp, content);
}
