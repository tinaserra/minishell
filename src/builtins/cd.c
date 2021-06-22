#include "minishell.h"

void	update_pwd()
{
	char	*tmp;

	tmp = ft_strdup(g_ms->curdir);
	free(g_ms->curdir);
	g_ms->curdir= NULL;
	if (find_env(g_ms->env, "PWD") && find_env(g_ms->env, "OLDPWD"))
		set_env("OLDPWD", find_env(g_ms->env, "PWD"));
	g_ms->curdir = getcwd(NULL, 0);
	if (!g_ms->curdir)
	{
		printf("error\n");
		g_ms->curdir = ft_strjoin_free(tmp, "/.", 'L');
		return ;
	}
	if (find_env(g_ms->env, "PWD"))
		set_env("PWD", g_ms->curdir);
	free(tmp);
}

void	cd_builtin(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	if (!tmp)
	{
		if (chdir(find_env(g_ms->env, "HOME")))
		{
			printf("cd: HOME not set\n");
			g_ms->exit = 1;
			return ;
		}
	}
	else
	{
		if (chdir(tmp->word))
		{
			printf("cd: no such file or directory: %s\n", tmp->word);
			g_ms->exit = 1;
			return ;
		}
	}
	update_pwd();
}