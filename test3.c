# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/errno.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd && c)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd && s)
		write(fd, s, strlen(s));
}

void	printerrno_fd(int fd)
{
	char	*ret_error;

	printf("Je suis dans print errno\n");
	ret_error = strerror(errno);
	ft_putstr_fd(ret_error, fd);
	ft_putchar_fd('\n', fd);
}

void	exec_command(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printf("Error Forking\n");
	else if (pid == 0)		/* child process */
	{
		errno = 0;
		execvp(args[0], args);
		if (errno != 0)
			printerrno_fd(STDERR_FILENO);
		exit(1);
	}
	else					/* parent process */
		wait(NULL);
}

//if (errno != 0)
	//	printerrno_fd(STDERR_FILENO);

int main(int ac, char **av)
{
	char *ls[] = {av[1], NULL};
	char *cat[] = {av[1], av[2], NULL};
	char **cmd[] = {ls, cat, NULL};

	//errno = 0;
	exec_command(cat);
	//if (errno != 0)
	//		printerrno_fd(STDERR_FILENO);
}
