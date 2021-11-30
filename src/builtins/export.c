/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:39:21 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/30 14:55:44 by jode-vri         ###   ########.fr       */
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

void	export_run(char *identifier, char *content, int show, int is_plus)
{
	t_env	*tmp_env;

	tmp_env = get_env(g_ms->env, identifier);
	if (tmp_env)
	{
		if (is_plus)
			tmp_env->value = ft_strjoin_free(tmp_env->value, content, 'L');
		else
		{
			free(tmp_env->value);
			tmp_env->value = ft_strdup(content);
		}
	}
	else
		add_env(&g_ms->env, lst_new_env(ft_strdup(identifier), content, show));
}

int	export_check(t_token *tmp, char **id, char *content)
{
	int		is_plus;

	is_plus = 0;
	content++;
	if (!ft_isalpha(id[0][0]) && id[0][0] != '_')
	{
		error("not a valid identifier", "export", tmp->word, 1);
		return (0);
	}
	if (export_errors(id[0]))
	{
		error("not a valid identifier", "export", tmp->word, 1);
		return (0);
	}
	if (ft_strchr(id[0], '+') != NULL)
		is_plus = 1;
	if (is_plus)
		id = ft_split(id[0], "+");
	export_run(id[0], content, 1, is_plus);
	if (is_plus)
		ft_free_tab(id);
	return (1);
}

void	export_start(t_token *tmp, char *content, int *stop)
{
	char	**id;

	if (tmp && tmp->word)
	{
		content = ft_strchr(tmp->word, '=');
		if (content)
		{
			id = ft_split(tmp->word, "=");
			if (id[0] && content && content[0] == '=')
			{
				
				if (content)
				{
					if (!export_check(tmp, id, content))
						*stop = 1;
				}
				else
					error("not a valid identifier", "export", tmp->word, 1);
			}
			ft_free_tab(id);
		}
		else
			export_run(tmp->word, ft_strdup(""), 0, 0);
	}
}

void	export_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	char	*content;
	int		stop;

	tmp = cmd->args;
	stop = 0;
	content = NULL;
	if (!tmp)
		export_x(cmd->out);
	while (tmp && !stop)
	{
		if ((tmp && ft_strcmp(tmp->word, "") == 0))
		{
			error("not a valid identifier", "export", tmp->word, 1);
			break ;
		}
		export_start(tmp, content, &stop);
		tmp = tmp->next;
	}
}
