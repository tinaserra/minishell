#include "minishell.h"

void	get_cmds(t_minishell *ms)
{
	char	**cmds;
	int		i;
	int		j;
	int		k;
	int		len;

	cmds = ft_split(ms->line, ";");
	len = ft_strs_tab_size(cmds);
	ms->cmds = malloc(sizeof(char **) * len);
	i = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		while (cmds[i][j])
			j++;
		ms->cmds[i] = malloc(sizeof(char *) * (j + 1));
		ms->cmds[i] = ft_split(cmds[i], " ");
		i++;
		k++;
	}
}

void fonction() // parsing
{
	printf("[%s]\n", ms->line);
	//get_cmds(ms);
}