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

void	printerrno_fd(int fd, char *cmd, char *arg)
{
	char	*ret_error;

	printf("Je suis dans print errno\n");
	ret_error = strerror(errno);
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(cmd, fd);
	if (cmd)
		ft_putstr_fd(": ", fd);
	ft_putstr_fd(arg, fd);
	if (arg)
		ft_putstr_fd(": ", fd);
	ft_putstr_fd(ret_error, fd);
	ft_putchar_fd('\n', fd);
}

int	print_error(int error)
{
	ft_putstr_fd(g_str_error[error], STDERR_FILENO);
	return (0);
}
//int	print_error(char *str)
//{
//	ft_putstr_fd(str, STDERR_FILENO);
//	return (0);
//}