#include "minishell.h"

// printerrno_fd(STDERR_FILENO);

/*
** The following symbolic constants shall be defined for file streams:
**
** STDERR_FILENO
** 		File number of stderr; 2.
** STDIN_FILENO
** 		File number of stdin; 0.
** STDOUT_FILENO
** 		File number of stdout; 1.
*/

void	printerrno_fd(int fd)
{
	char	*ret_error;

	ret_error = strerror(errno);
	ft_putstr_fd(ret_error, fd);
	ft_putchar_fd('\n', fd);
}

int	print_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	//exit(EXIT_FAILURE);
	return (0);
}