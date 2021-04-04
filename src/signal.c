#include "minishell.h"

void	sig_quit(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
	ft_putstr_fd(1, ms.env.user);
	ft_putstr_fd(1, " ➜ \x1B[34m");
	ft_putstr_fd(1, ms.env.pwd);
	ft_putstr_fd(1, "\x1B[0m ");
}

void	sig_int(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
	ft_putstr_fd(1, ms.env.user);
	ft_putstr_fd(1, " ➜ \x1B[34m");
	ft_putstr_fd(1, ms.env.pwd);
	ft_putstr_fd(1, "\x1B[0m ");
}