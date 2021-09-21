#include "minishell.h"

void	update_pwd(void)
{
	char	*tmp;

	tmp = ft_strdup(g_ms->curdir);
	free(g_ms->curdir);
	g_ms->curdir = NULL;
	if (find_env(g_ms->env, "PWD") && find_env(g_ms->env, "OLDPWD"))
		set_env("OLDPWD", find_env(g_ms->env, "PWD"));
	g_ms->curdir = getcwd(NULL, 0);
	if (!g_ms->curdir)
	{
		printf("error pute\n"); //  ?????????
		g_ms->curdir = ft_strjoin_free(tmp, "/.", 'L');
		return ;
	}
	if (find_env(g_ms->env, "PWD"))
		set_env("PWD", g_ms->curdir);
	free(tmp);
}

int	have_permission(t_cmd *cmd)
{
	DIR	*dir;

	errno = 0;
	dir = opendir(cmd->args->word);
	if (dir == NULL || errno != 0)
	{
		g_ms->status = 1;
		print_error(ERRNO, "cd", cmd->args->word);
		return (0);
	}
	else
		closedir(dir);
	return (1);
}

void	cd_builtin(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	if (!tmp)
	{
		if (chdir(find_env(g_ms->env, "HOME")) != 0)
		{
			g_ms->status = 1;
			print_error(HOME, "cd", NULL);
			g_ms->exit = 1;
			return ;
		}
	}
	else
	{
		if (have_permission(cmd) && chdir(tmp->word) != 0)
		{
			g_ms->status = 1;
			print_error(ERRNO, "cd", tmp->word);
			g_ms->exit = 1;
			return ;
		}
	}
	update_pwd();
}
