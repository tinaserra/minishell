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
		printf("|%s|\n", ms->cmds[i]);
		i++;
	}
}

void fonction(t_minishell *ms) // parsing
{
	get_cmds(ms);
}