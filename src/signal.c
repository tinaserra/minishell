#include "minishell.h"

void	sig_quit(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
	ft_putstr_fd(2, "\x1B[34mminishell-0.1$>\x1B[0m ");
}

void	sig_int(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
	ft_putstr_fd(2, "\x1B[34mminishell-0.1$>\x1B[0m ");
}