#include "minishell.h"

void	pwd_builtin(void)
{
	char	*pwd;

	pwd = find_env(g_ms->env, "PWD");
	if (pwd)
	{
		ft_putstr_fd(pwd, 1);
		ft_putchar_fd('\n', 1);
	}
}
