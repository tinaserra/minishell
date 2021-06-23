#include "minishell.h"

void	add_history(char *line)
{
	char	*file;
	int		fd;

	if (find_env(g_ms->env, "HOME") == NULL)
		return ;
	file = ft_strjoin(ft_strdup(find_env(g_ms->env, "HOME")),
			"/.minishell_history");
	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0600);
	if (fd != -1)
	{
		ft_lstadd_front(&g_ms->history, ft_lstcreate(ft_strdup(line)));
		g_ms->history_pos = -1;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
	free(file);
}

int	get_history(void)
{
	char	*file;
	char	*line;
	int		fd;
	int		ret;

	if (find_env(g_ms->env, "HOME") == NULL)
		return (0);
	file = ft_strjoin(ft_strdup(find_env(g_ms->env, "HOME")),
			"/.minishell_history");
	fd = open(file, 0, O_RDONLY);
	if (fd != -1)
	{
		line = NULL;
		ret = ft_get_next_line(fd, &line);
		while (ret == 1)
		{
			ft_lstadd_front(&g_ms->history, ft_lstcreate(line));
			line = NULL;
			ret = ft_get_next_line(fd, &line);
		}
		free(line);
		close(fd);
	}
	free(file);
	return (1);
}

void	set_history(long c)
{
	g_ms->line = NULL;
	g_ms->cursor = 0;
	if (c == 4283163)
	{
		if (g_ms->history_pos >= ft_lstsize(g_ms->history) - 1)
			return ;
		g_ms->line = ft_strdup(ft_lstfind_pos(g_ms->history,
					++(g_ms->history_pos))->data);
	}
	if (c == 4348699)
	{
		if (g_ms->history_pos > 0)
			g_ms->line = ft_strdup(ft_lstfind_pos(g_ms->history,
						--(g_ms->history_pos))->data);
		else
		{
			g_ms->history_pos = -1;
			g_ms->line = NULL;
		}
	}
	g_ms->cursor = ft_strlen(g_ms->line);
	write(1, "\r", 1);
	print_term("cd");
	print_prompt();
	ft_putstr_fd(1, g_ms->line);
}

void	free_history(void)
{
	t_list	*tmp;

	while (g_ms->history)
	{
		tmp = g_ms->history->next;
		free(g_ms->history->data);
		free(g_ms->history);
		g_ms->history = tmp;
	}
}
