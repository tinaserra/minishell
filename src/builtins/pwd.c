#include "minishell.h"

void	pwd_builtin(t_cmd *cmd)
{
	char	*pwd;

	if (cmd->out == 0)
		cmd->out = 1;
	pwd = find_env(g_ms->env, "PWD");
	if (pwd)
	{
		if (cmd->args)
		{
			printf("pwd: too many arguments\n");
			return ;
		}
		ft_putstr_fd(pwd, cmd->out);
		ft_putchar_fd('\n', cmd->out);
	}
}
