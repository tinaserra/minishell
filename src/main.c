#include "minishell.h"

void	print_prompt()
{
	char	**pwd;

	pwd = ft_split(find_env(ms->env, "PWD"), "/");
	ft_putstr_fd(1, "\x1b[33m");
	ft_putstr_fd(1, find_env(ms->env, "USER"));
	ft_putstr_fd(1, "\x1b[31m ➜");
	ft_putstr_fd(1, "\x1b[34m ");
	ft_putstr_fd(1, pwd[ft_strs_tab_size(pwd) - 1]);
	ft_putstr_fd(1, " \x1b[0m");
	ft_free_tab(pwd);
}

void	minishell()
{
	char	c;
	int		ret;
	int		i;

	i = 0;
	print_prompt();
	while (read(0, &c, 1) == 1)
	{
		if ((ret = handle_termcaps(ms, c)) == -1)
			exit(EXIT_SUCCESS);
		else
		{
			ms->line = ft_realloc(ms->line, i + 2);
			if (c == KEY_ENTER)
			{
				ft_putstr_fd(1, "\n");
				if (ms->line)
					fonction();
				ft_bzero(ms->line, ft_strlen((char *)ms->line));
				i = 0;
				ms->cursor = 0;
				print_prompt();
			}
			else
			{
				write(1, &c, 1);
				ms->cursor++;
				ms->line[i] = c;
				ms->line[i + 1] = '\0';
				i++;
			}
		}
	}
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;

	ms = malloc(sizeof(t_minishell));
	ft_bzero(ms, sizeof(t_minishell));
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	if (!init_env(env))
		exit(EXIT_FAILURE);
	if (tgetent(NULL, find_env(ms->env, "TERM")) != 1)
	{
		printf("Unable to initialize TERM env");
		exit(EXIT_FAILURE);
	}
	set_raw();
	minishell();
}