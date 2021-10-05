/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:06:09 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/05 14:40:26 by jode-vri         ###   ########.fr       */
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

static t_env	*lstfree_first(t_env *l, t_env *cur)
{
	l = l->next;
	free(cur->name);
	free(cur->value);
	free(cur);
	return (l);
}

static t_env	*lstfree_at(t_env *l, int pos)
{
	t_env	*prec;
	t_env	*cur;
	int		i;

	prec = l;
	cur = l;
	if (l == NULL)
		return (NULL);
	if (pos == 0)
		return (lstfree_first(l, cur));
	if (pos > lstsize(l))
		return (NULL);
	i = -1;
	while (++i < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur->name);
	free(cur->value);
	free(cur);
	return (l);
}

void	unset_builtin(t_cmd *cmd)
{
	t_token	*tmp;
	t_env	*env;
	int pos;

	(void)cmd;
	tmp = cmd->args;
	pos = lstfind_pos(g_ms->env, tmp->word);
	while (tmp)
	{
		if (is_valid_envv(tmp->word))
		{
			env = get_env(g_ms->env, tmp->word);
			if (env)
				g_ms->env = lstfree_at(g_ms->env, pos);
		}
		else
			error("not a valid identifier", "unset", tmp->word, 1);
		tmp = tmp->next;
	}
}
