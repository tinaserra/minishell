#include "minishell.h"

void		status_child(void)
{
	if (WIFEXITED(g_ms->pid))
		g_ms->status = WEXITSTATUS(g_ms->pid);
	if (WIFSIGNALED(g_ms->pid))
	{
		g_ms->status = WTERMSIG(g_ms->pid);
		if (g_ms->status != 131)
			g_ms->status += 128;
	}
}

char	*find_binary(t_cmd *cmd, int show)
{
	struct stat stats;
	char		*binary;

	binary = check_path(cmd);
	if (!binary)
	{
		if (lstat(cmd->cmd, &stats))
		{
			if (show)
				print_error(CMD, cmd->cmd, NULL);
			free(binary);
			return (NULL);
		}
		free(binary);
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