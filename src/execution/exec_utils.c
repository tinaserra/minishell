#include "minishell.h"

int	count_quote(char *s)
{
	int	i;
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\"' && !s_quote)
		{
			if (d_quote == 1)
				d_quote = 0;
			else
				d_quote = 1;
		}
		if (s[i] == '\'' && !d_quote)
		{
			if (s_quote == 1)
				s_quote = 0;
			else
				s_quote = 1;
		}
	}
	if (s_quote || d_quote)
		return (-1);
	else
		return (1);
}

int	edit_args(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	while (tmp)
	{
		if (count_quote(tmp->word) == -1)
		{
			printf("minishell: Unclosed quote\n");
			return (0);
		}
		tmp->word = handle_quotes(tmp->word, 1);
		tmp = tmp->next;
	}
	return (1);
}

int is_redirection(char *s)
{
	if (ft_strcmp(s, "<") == 0 || ft_strcmp(s, ">") == 0 
		|| ft_strcmp(s, ">>") == 0 || ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}

int	lst_size(t_cmd *cmd)
{
	t_token *liste;
	int		len;

	liste = cmd->args;
	len = 0;
	while (liste)
	{
		if (!is_redirection(liste->word))
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
		if (!is_redirection(liste->word))
		{
			aaargs[i] = ft_strdup(liste->word);
			i++;
		}
		else
			liste = liste->next;
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
		binary = ft_strjoin_free(ft_strdup(path[i]), "/", 'L');
		binary = ft_strjoin_free(binary, cmd->cmd, 'L');
		if (lstat(binary, &stats) == 0)
		{
			ft_free_tab(path);
			return (binary);
		}
		free(binary);
		i++;
	}
	ft_free_tab(path);
	return (NULL);
}