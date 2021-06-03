#include "minishell.h"

int		minishell()
{
	long	c;

	c = 0;
	while (read(0, &c, sizeof(c)) > 0)
	{
		if (c == 4)
		{
			write(1, "exit\n", 5);
			break ;
		}
		handle_termcaps(c);
		c = 0;
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
	if (tgetent(ms->term, find_env(ms->env, "TERM")) != 1)
	{
		printf("Unable to initialize TERM env\n");
		exit(EXIT_FAILURE);
	}
	set_raw();
	print_prompt();
	minishell();
	free_env();
	free_history();
	free_commands();
	free(ms->line);
	free(ms->term);
	free(ms);
}