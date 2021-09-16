#include "minishell.h"

void	edit_args(t_cmd *cmd)
{
	t_token	*tmp;
	//int		is_env;

	tmp = cmd->args;
	while (tmp)
	{
		//is_env = 0;
		/*if (tmp->word && tmp->word[0] == '$')
			is_env = 1;*/
		tmp->word = handle_quotes(tmp->word, 1);
		tmp = tmp->next;
	}
}

int	lst_size(t_cmd *cmd)
{
	t_token *liste;
	int		len;

	liste = cmd->args;
	len = 0;
	while (liste)
	{
		len++;
		liste = liste->next;
	}
	return (len);
}

char	**list_to_tab(t_cmd *cmd)
{
	t_token	*liste;
	int		len;
	int		i;
	char	**aaargs;

	len = lst_size(cmd);
	aaargs = malloc(sizeof(char *) * (len + 2));
	if (aaargs == NULL)
		return (NULL);
	liste = cmd->args;
	aaargs[0] = ft_strdup(cmd->cmd);
	i = 1;
	while (liste)
	{
		aaargs[i] = ft_strdup(liste->word);
		i++;
		liste = liste->next;
	}
	aaargs[i] = NULL;
	return(aaargs);
}

char	*check_path(t_cmd *cmd)
{
	char		**path;
	char		*binary;
	struct stat	stats;
	
	int		i;
	(void)cmd;

	path = ft_split(find_env(g_ms->env, "PATH"), ":");
	i = 0;
	while (path[i])
	{
		binary = ft_strjoin(path[i], "/");
		binary = ft_strjoin_free(binary, cmd->cmd, 'L');
		if (lstat(binary, &stats) == 0)
		{
			//ft_free_tab(path);
			return (binary);
		}
		free(binary);
		i++;
	}
	//ft_free_tab(path);
	return (NULL);
}