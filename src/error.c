#include "minishell.h"
#include "error.h"

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

// print_error(NUMBER, "cmd", "arg");

void	print_error(int error, char *cmd, char *arg) // int status
{
	char	*error_message;

	// if (status > 0)
	// 	g_ms->status = status;

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	if (cmd)
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(": ", STDERR_FILENO);
	if (error == ERRNO)
	{
		error_message = strerror(errno);
		ft_putstr_fd(error_message, STDERR_FILENO);
	}
	else
		ft_putstr_fd(g_str_error[error], STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
