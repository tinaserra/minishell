/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:44 by vserra            #+#    #+#             */
/*   Updated: 2021/11/08 08:17:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Connaître le code erreur d’un appel à une commande / d'un signal :
** waitpid(pid_t pid, int *status, int options);

** WIFEXITED(status) = renvoie vrai si le fils s'est terminé normalement,
** c'est-à-dire par un appel à exit(3) ou _exit(2), ou bien par un retour de main().
** Et dans ce cas on peut appeller : WEXITSTATUS(status) = renvoie le code
** de sortie du fils. Ce code est constitué par les 8 bits de poids faibles de
** l'argument status que le fils a fourni à exit(3) ou à _exit(2) ou l'argument
** d'une commande de retour dans main(). "Cette macro ne peut être évaluée
** que si WIFEXITED a renvoyé vrai".

** WIFSIGNALED(status) = renvoie vrai si le fils s'est terminé à cause d'un signal.
** Et dans ce cas on peut appeller : WTERMSIG(status) = renvoie le numéro du signal
** qui a causé la fin du fils. "Cette macro ne peut être évaluée
** que si WIFSIGNALED a renvoyé vrai".

** void		status_child(void)
** {
** 	if (WIFEXITED(g_pid))
** 		g_status = WEXITSTATUS(g_pid);
** 	if (WIFSIGNALED(g_pid))
** 	{
** 		g_status = WTERMSIG(g_pid);
** 		if (g_status != 131)
** 			g_status += 128;
** 	}
** }

*/

void	status_child(int status)
{
	if (WIFEXITED(status))
		g_ms->status = WEXITSTATUS(status);
	if (WIFSIGNALED(g_ms->pid))
	{
		g_ms->status = WTERMSIG(g_ms->pid);
		if (g_ms->status != 131)
			g_ms->status += 128;
	}
}

char	*find_binary(t_cmd *cmd, int show)
{
	(void)show;
	struct stat	stats;
	char		*binary;

	if (!cmd)
		return (NULL);
	binary = check_path(cmd);
	if (!binary)
	{
		if (lstat(cmd->cmd, &stats))
		{
			//if (show && !is_builtin(cmd->cmd))
			//	error("command not found", cmd->cmd, NULL, 127);
			free(binary);
			return (NULL);
		}
		free(binary);
		if (S_ISDIR(stats.st_mode) != 0)
			return (NULL);
		binary = ft_strdup(cmd->cmd);
	}
	return (binary);
}

int	find_all_binary(t_cmd *cmd)
{
	t_cmd	*tmpp;
	char	*bin;

	tmpp = cmd;
	while (tmpp)
	{
		bin = find_binary(tmpp, 1);
		if (!bin)
		{
			free(bin);
			return (0);
		}
		free(bin);
		tmpp = tmpp->next;
	}
	return (1);
}

static int	count_quote(char *s)
{
	int	i;
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	i = -1;
	while (s && s[++i])
	{
		if (s[i] == '\"' && !s_quote)
		{
			if (d_quote == 1)
				d_quote = 0;
			else
				d_quote = 1;
		}
		if (s[i] == '\'' && !d_quote)
		{
			if (s_quote == 1)
				s_quote = 0;
			else
				s_quote = 1;
		}
	}
	if (s_quote || d_quote)
		return (-1);
	else
		return (1);
}

int	edit_args(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	if (count_quote(cmd->cmd) == -1)
	{
		printf("minishell: Unclosed quote\n");
		return (0);
	}
	cmd->cmd = handle_quotes(cmd->cmd, 1);
	while (tmp)
	{
		if (count_quote(tmp->word) == -1)
		{
			printf("minishell: Unclosed quote\n");
			return (0);
		}
		tmp->word = handle_quotes(tmp->word, 1);
		tmp = tmp->next;
	}
	return (1);
}
