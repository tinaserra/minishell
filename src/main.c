#include "minishell.h"

int	minishell(void)
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

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	g_ms = malloc(sizeof(t_minishell));
	ft_bzero(g_ms, sizeof(t_minishell));
	g_ms->history_pos = -1;
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	if (!init_env(env) || !get_history())
		exit(EXIT_FAILURE);
	if (tgetent(g_ms->term, find_env(g_ms->env, "TERM")) != 1)
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
	free(g_ms->line);
	free(g_ms->term);
	free(g_ms);
}
