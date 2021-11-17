/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:38:47 by vserra            #+#    #+#             */
/*   Updated: 2021/11/12 15:47:09 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Connaître le code erreur d’un appel à une commande / d'un signal :
** waitpid(pid_t pid, int *status, int options);
**
** WIFEXITED(status) = renvoie vrai si le fils s'est terminé normalement,
** c'est-à-dire par un appel à exit(3) ou _exit(2), ou bien par un retour de 
** main().
** Et dans ce cas on peut appeller : WEXITSTATUS(status) = renvoie le code
** de sortie du fils. Ce code est constitué par les 8 bits de poids faibles de
** l'argument status que le fils a fourni à exit(3) ou à _exit(2) ou l'argument
** d'une commande de retour dans main(). "Cette macro ne peut être évaluée
** que si WIFEXITED a renvoyé vrai".
**
** WIFSIGNALED(status) = renvoie vrai si le fils s'est terminé à cause d'un 
** signal.
** Et dans ce cas on peut appeller : WTERMSIG(status) = renvoie le numéro du 
** signal
** qui a causé la fin du fils. "Cette macro ne peut être évaluée
** que si WIFSIGNALED a renvoyé vrai".
**
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

static void	exec_binary2(t_cmd *cmd, pid_t pid, int pipe1[2])
{
	int	status;
	int	pipe2[2];

	if (pipe(pipe2) < 0)
		return ;
	if (cmd->type == PIPE)
	{
		edit_args(cmd->next);
		redirect(cmd->next);
		while (cmd->next && !cmd->next->cmd)
		{
			edit_args(cmd);
			redirect(cmd);
			cmd = cmd->next;
		}
		if (cmd->next)
			exec_binary(cmd->next, pipe1, pipe2);
	}
	close_all(pipe1, pipe2);
	waitpid(pid, &status, WUNTRACED);
	status_child(cmd, status);
}

void	exec_bin_check(t_cmd *cmd)
{
	if (!is_builtin(cmd->cmd))
		g_ms->fork = 1;
	cmd->bin = find_binary(cmd, 1);
	cmd->argss = list_to_tab(cmd);
	if ((access(cmd->cmd, F_OK) == 0 && access(cmd->cmd, X_OK) == -1))
		error("Permission denied", cmd->cmd, NULL, 1);
}

void	exec_binary(t_cmd *cmd, int pipe1[2], int pipe2[2])
{
	exec_bin_check(cmd);
	g_ms->pid = fork();
	if (g_ms->pid < 0)
		error("error forking", NULL, NULL, -1);
	else if (g_ms->pid == 0)
	{
		if (cmd->in == -1 || cmd->out == -1)
			exit(1);
		handle_fds(cmd, pipe1, pipe2);
		execute(cmd);
		close(cmd->in);
		close(cmd->out);
	}
	else
	{
		if (cmd->type == PIPE && cmd->prev && cmd->prev->type == PIPE
			&& !close(pipe1[1]) && !close(pipe1[0]))
			exec_binary2(cmd, g_ms->pid, pipe2);
		else
			exec_binary2(cmd, g_ms->pid, pipe1);
	}
}

static void	exec_switch(t_cmd *cmd, int pipe1[2])
{
	if (ft_strcmp(cmd->cmd, "cd") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		cd_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "export") == 0 && cmd->args)
		export_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		unset_builtin(cmd);
	else if (ft_strcmp(cmd->cmd, "exit") == 0 && cmd->type != PIPE
		&& (!cmd->prev || cmd->prev->type != PIPE))
		exit_builtin(cmd);
	else if (!cmd->prev || (cmd->prev && cmd->prev->type != PIPE))
		exec_binary(cmd, pipe1, NULL);
}

void	exec_start(void)
{
	t_cmd	*cmd;
	int		pipe1[2];

	cmd = g_ms->cmds;
	while (cmd)
	{
		edit_args(cmd);
		redirect(cmd);
		if (cmd->cmd && cmd->in != -1 && cmd->out != -1)
		{
			if (pipe(pipe1))
				return ;
			exec_switch(cmd, pipe1);
			close(pipe1[0]);
			close(pipe1[1]);
		}
		while (cmd->type == PIPE)
			cmd = cmd->next;
		cmd = cmd->next;
	}
}
