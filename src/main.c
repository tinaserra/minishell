#include "minishell.h"

/**
 * print_prompt
 * * print prompt
 * @param mode
 */

void	print_prompt(void)
{
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

int		minishell()
{
	long	c;

	c = 0;
	while (read(0, &c, sizeof(c)) > 0)
	{
		if (c == 4)
		{
			write(1, "\n", 1);
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
	set_raw();
	print_prompt();
	minishell();
	free_env();
	free_history();
	free(ms->line);
	free(ms);
}