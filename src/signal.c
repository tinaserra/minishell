#include "minishell.h"

/**
 * sig_quit
 * * handle CTRL + \ 
 * @param c exit code
 */

void	sig_quit(int c)
{
	(void)c;

	ft_putstr_fd(1, "\n");
	print_prompt();
}

/**
 * sig_int
 * * handle CTRL + C
 * @param c exit code
 */

void	sig_int(int c)
{
	(void)c;

	ft_putstr_fd(1, "\n");
	print_prompt();
}
