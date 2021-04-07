#include "minishell.h"

// void	get_cmds(t_minishell *ms)
// {
// 	char	**cmds;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		len;

// 	cmds = ft_split((char *)ms->line, ";");
// 	len = ft_strs_tab_size(cmds);
// 	ms->cmds = malloc(sizeof(char **) * len);
// 	i = 0;
// 	k = 0;
// 	while (i < len)
// 	{
// 		j = 0;
// 		while (cmds[i][j])
// 			j++;
// 		ms->cmds[i] = malloc(sizeof(char *) * (j + 1));
// 		ms->cmds[i] = ft_split(cmds[i], " ");
// 		i++;
// 		k++;
// 	}
// }

	/*pid_t	pid;
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
	}*/

// void	echo_builtin(t_minishell *ms, int i)
// {
// 	int 	j;
// 	int		n;
// 	int 	k;
// 	char	*path_var;
// 	char	*res;

// 	j = 0;
// 	n = 0;
// 	if (ms->cmds[i][1] == NULL)
// 		ft_putstr_fd(1, "\n");
// 	if (ft_strcmp(ms->cmds[i][1], "-n") == 0)
// 	{
// 		j++;
// 		n = 1;
// 	}
// 	while (ms->cmds[i][++j])
// 	{		
// 		k = -1;
// 		while (ms->cmds[i][j][++k])
// 		{
// 			if (ms->cmds[i][j][k] == '$')
// 			{
// 				path_var = ft_strtrim(ms->cmds[i][j], "$");
// 				res = getenv(path_var);
// 				ft_putstr_fd(1, res);
// 				while (ms->cmds[i][j][k] && ms->cmds[i][j][k] != ' ')
// 					k++;
// 			}
// 			else
// 				ft_putchar_fd(ms->cmds[i][j][k], 1);
// 		}
// 		if (ms->cmds[i][j + 1] != NULL)
// 			ft_putstr_fd(1, " ");
// 		else if (ms->cmds[i][j + 1] == NULL && !n)
// 			ft_putstr_fd(1, "\n");
// 	}
// }

void fonction()
{
	int	i;

	i = -1;
	// get_cmds(&ms);
	// while (ms.cmds[++i])
	// {
	// 	if (ft_strcmp(ms.cmds[i][0], "echo") == 0)
	// 		echo_builtin(&ms, i);
	// }
}