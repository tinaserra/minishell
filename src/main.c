#include "minishell.h"

void	print_prompt(int mode)
{
	(void)mode;
	char	**pwd;

	pwd = ft_split(find_env(ms->env, "PWD"), "/");
	ft_putstr_fd(1, "\x1b[33m");
	ms->prompt_size += ft_putstr_fd(1, find_env(ms->env, "USER"));
	ft_putstr_fd(1, "\x1b[31m ➜");
	ft_putstr_fd(1, "\x1b[34m ");
	ms->prompt_size += ft_putstr_fd(1, pwd[ft_strs_tab_size(pwd) - 1]);
	ft_putstr_fd(1, " \x1b[0m");
	ms->prompt_size += 3;
	ft_free_tab(pwd);
	print_term("me");	
}

char	*line_join(char *s1, char c)
{
	char	*res;
	char	*s2;

	s2 = malloc(sizeof(char) * 2);
	s2[0] = c;
	s2[1] = '\0';
	res = ft_strjoin(s1, s2);
	free(s2);
	return (res);
}

int		minishell2(t_minishell *ms, char **line)
{
	char	*tmp;

	write(1, "\n", 1);
	ms->cursor = 0;
	tmp = *line;
	*line = ft_strtrim(*line, "\f\t\n\r\v");
	if (ft_strlen(*line) != 0)
	{
		add_history(*line);
		ms->line = ft_strdup(*line);
		fonction();
		free(*line);
		*line = NULL;
	}
	print_prompt(0);
	return (1);
}

int		minishell()
{
	long	c;

	c = 0;
	while (read(0, &c, sizeof(c)) > 0)
	{
		if (c == 4)
			return (EXIT_SUCCESS);
		handle_termcaps(c);
	}
	return (1);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;

	ms = malloc(sizeof(t_minishell));
	ft_bzero(ms, sizeof(t_minishell));
	ms->history_pos = -1;
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	if (!init_env(env) || !get_history(ms))
		exit(EXIT_FAILURE);
	if (tgetent(NULL, find_env(ms->env, "TERM")) != 1)
	{
		printf("Unable to initialize TERM env");
		exit(EXIT_FAILURE);
	}
	set_raw();
	print_prompt(0);
	minishell();
}