/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:30 by vserra            #+#    #+#             */
/*   Updated: 2021/11/12 15:42:28 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute2(t_cmd *cmd)
{
	int	exitt;

	if (cmd->bin)
		execve(cmd->bin, cmd->argss, NULL);
	else
		error("command not found", cmd->cmd, NULL, 127);
	exitt = g_ms->status;
	free_all();
	exit(exitt);
}

void	execute(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->cmd, "echo"))
		echo_builtin(cmd, cmd->out);
	else if (!ft_strcmp(cmd->cmd, "env"))
		env_builtin(cmd->out);
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		pwd_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "cd"))
		cd_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "exit"))
		exit_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "export"))
		export_builtin(cmd);
	else if (!ft_strcmp(cmd->cmd, "unset"))
		exit(0);
	else if (cmd->cmd && g_ms->env && cmd->argss)
		execute2(cmd);
	free_all();
	exit(0);
}

int	is_builtin(char *s)
{
	if (ft_strcmp(s, "echo") == 0)
		return (1);
	if (ft_strcmp(s, "env") == 0)
		return (1);
	if (ft_strcmp(s, "pwd") == 0)
		return (1);
	if (ft_strcmp(s, "cd") == 0)
		return (1);
	if (ft_strcmp(s, "exit") == 0)
		return (1);
	if (ft_strcmp(s, "export") == 0)
		return (1);
	if (ft_strcmp(s, "unset") == 0)
		return (1);
	return (0);
}

char	**list_to_tab(t_cmd *cmd)
{
	char	**args;
	t_token	*tmp;
	int		i;

	i = 1;
	if (!cmd->cmd)
		return (NULL);
	args = ft_calloc(1, sizeof(char *) *(tokens_list_size(cmd->args) + 2));
	if (!args)
		exit(0);
	args[0] = ft_strdup(cmd->cmd);
	tmp = cmd->args;
	while (tmp)
	{
		args[i] = ft_strdup(tmp->word);
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

char	*check_path(t_cmd *cmd)
{
	char		**path;
	char		*binary;
	struct stat	stats;
	int			i;

	path = ft_split(find_env(g_ms->env, "PATH"), ":");
	i = 0;
	while (path && path[i])
	{
		binary = ft_strjoin_free(ft_strdup(path[i]), "/", 'L');
		binary = ft_strjoin_free(binary, cmd->cmd, 'L');
		if (lstat(binary, &stats) == 0)
		{
			ft_free_tab(path);
			return (binary);
		}
		free(binary);
		i++;
	}
	ft_free_tab(path);
	return (NULL);
}
