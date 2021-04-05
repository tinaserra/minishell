#include "minishell.h"

void	get_cmds(t_minishell *ms)
{
	char	**cmds;
	int		i;
	int		len;

	cmds = ft_split(ms->line, ";");
	len = ft_strs_tab_size(cmds);
	ms->cmds = malloc(sizeof(char *) * len);
	i = 0;
	while (i < len)
	{
		ms->cmds[i] = ft_strtrim(cmds[i], " ");
		i++;
	}
}

void fonction(t_minishell *ms)
{
	pid_t	pid;
	int		status;
	int		i;
	char	**args;

	get_cmds(ms);
	args = NULL;
	pid = 0;
	i = -1;
	while (ms->cmds[++i])
	{
		if ((pid = fork()) == 0)
		{
			if ((execve(ms->cmds[0], ms->cmds, NULL)) == -1)
				exit(errno);
		}
		else
			waitpid(pid, &status, 0);
	}
}