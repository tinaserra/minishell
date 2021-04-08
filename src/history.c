#include "minishell.h"

void    add_history(char *line)
{
    char    *file;
    int     fd;

    if (find_env(ms->env, "HOME") == NULL)
        return ;
    file = ft_strjoin(ft_strdup(find_env(ms->env, "HOME")), "/.minishell_history");
    if ((fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0600)) != -1)
    {
        ft_lstadd_front(&ms->history, ft_lstnew(ft_strdup(line)));
        ms->history_pos = -1;
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        close(fd);
    }
    free(file);
}

int     get_history(t_minishell *ms)
{
    char    *file;
    char    *line;
    int     fd;
    int     ret;

    if (find_env(ms->env, "HOME") == NULL)
        return (0);
    file = ft_strjoin(ft_strdup(find_env(ms->env, "HOME")), "/.minishell_history");
    if ((fd = open(file, 0, O_RDONLY)) != -1)
    {
        line = NULL;
        while ((ret = get_next_line(fd, &line)) == 1)
        {
            ft_lstadd_front(&ms->history, ft_lstnew(line));
            line = NULL;
        }
        free(line);
        close(fd);
    }
    free(file);
    return (1);
}

void	set_history(char c, char **line)
{
    ms->cursor = 0;
	if (c == 65)
	{
		if (ms->history_pos >= ft_lstsize(ms->history) - 1)
			return ;
		*line = ft_strdup(ft_lst_find_pos(ms->history, ++(ms->history_pos))->content);
	}
	if (c == 66)
	{
        if (ms->history_pos > 0)
		    *line = ft_strdup(ft_lst_find_pos(ms->history, --(ms->history_pos))->content);
        else
        {
            ms->history_pos = -1;
            *line = NULL;
        }
	}
	ms->cursor = ft_strlen(*line);
	write(1, "\r", 1);
	print_term("ce");
    print_prompt();
    ft_putstr_fd(1, *line);
}