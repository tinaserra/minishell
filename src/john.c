#include "minishell.h"

// void	get_cmds(t_minishell *ms)
// {
	
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

static void	execute(t_cmds *cmds)
{
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		echo_builtin(cmds);
}

void 		fonction()
{
	char	**cmdss;
	t_cmds	cmds;
	int		i;
	int		j;

	cmds.cmds_list = malloc(sizeof(t_list));
	ft_bzero(&cmds, sizeof(t_cmds));
	cmdss = ft_split((char *)ms->line, ";");
	free(ms->line);
	i = -1;
	while (cmdss[++i])
	{
		cmds.args = ft_split(cmdss[i], "\f\t\n\r\v ");
		cmds.cmd = cmds.args[0];
		j = 0;
		while (cmds.args[++j])
			ft_lstadd_back(&cmds.cmds_list, ft_lstnew(cmds.args[j]));
		execute(&cmds);
		free(cmds.cmd);
		//TODO: free cmds.cmds_list
		cmds.cmds_list = NULL;
	}
	ft_free_tab(cmdss);
}