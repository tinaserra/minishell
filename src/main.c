#include "minishell.h"

void	set_raw()
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

void	print_prompt()
{
	ft_putstr_fd(1, "\x1b[33m");
	ft_putstr_fd(1, find_env(ms->env, "USER"));
	ft_putstr_fd(1, "\x1b[31m ➜");
	ft_putstr_fd(1, "\x1b[34m minishell \x1b[0m");
}

int		handle_termcaps(char c)
{
	if (c == 4)
	{
		ft_putstr_fd(1, "exit\n");
		return (-1);
	}
	if (c == 65 || c == 66)
	{
		//history
	}
	return (1);
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
		if ((ret = handle_termcaps(c)) == -1)
			exit(EXIT_SUCCESS);
		else
		{
			ms->line = ft_realloc(ms->line, i + 2);
			if (c == 10)
			{
				ft_putstr_fd(1, "\n");
				if (ms->line)
					fonction();
				print_prompt();
			}
			else
			{
				write(1, &c, 1);
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
	(void)env;
	//int	ret;

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