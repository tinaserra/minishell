#include "minishell.h"

/**
 * sig_quit
 * * handle CTRL + C
 * @param c exit code
 */

void	sig_quit(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
}

/**
 * sig_int
 * * handle CTRL + \
 * @param c exit code
 */

void	sig_int(int c)
{
	(void)c;

	ft_putstr_fd(2, "\b\b  ");
	ft_putstr_fd(2, "\n");
}
