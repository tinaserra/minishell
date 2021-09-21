#include "minishell.h"

void	pwd_builtin(t_cmd *cmd)
{
	char	*pwd;

	pwd = find_env(g_ms->env, "PWD");
	if (pwd)
	{
		if (cmd->args)
		{
			printf("pwd: too many arguments\n");
			return ;
		}
		ft_putstr_fd(pwd, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
