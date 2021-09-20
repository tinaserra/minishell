#include "minishell.h"
#include "error.h"

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

// printerrno_fd(STDERR_FILENO, "cd", cmd->args->word);

// print_error(NUMBER, "cmd", "arg");


void	print_error(int error, char *cmd, char *arg) // enlever le 1er arg
{
	char	*error_message;

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
