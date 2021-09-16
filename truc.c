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

int pipeCreation(char **s1, char **s2)
{
	int fd[2];
	pid_t pid;
	pid_t pid2;
	int	status;
	int	status2;

	pipe(fd);

	pid = fork();
	if (pid == 0)
	{
		//commande 1
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execvp(s1[0], s1);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		//commande 2
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execvp(s2[0], s2);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status2, 0);
}

int main(int ac, char **av)
{
	char *ls[] = {av[1], NULL};
	char *cat[] = {av[2], av[3], NULL};
	char **cmd[] = {ls, cat, NULL};
	char *line;

	pipeCreation(ls, cat);
	while ((line = readline("minishell >")))
	{
		pipeCreation(ls, cat);
		printf("\nlkjljabc\n");
	}
}


//void exec_pipe(char *cmd, char *cmd2, char **s1, char **s2) // EXEC_PIPE
//{
//	int		fd[2];
//	pid_t	pid;
//	pid_t	pid2;
//	int		status;
//	int		status2;

//	if (pipe(fd) == -1)
//		print_error("Error Piping\n");
//	pid = fork();
//	if (pid < 0)
//		print_error("Error Forking\n");
//	if (pid == 0) /* commande 1 */
//	{
//		dup2(fd[WRITE], 1);
//		close(fd[READ]);
//		close(fd[WRITE]);
//		execve(cmd, s1, NULL);
//		exit(EXIT_SUCCESS);
//	}
//	pid2 = fork();
//	if (pid2 < 0)
//		print_error("Error Forking\n");
//	if (pid2 == 0) /* commande 2 */
//	{
//		dup2(fd[READ], 0);
//		close(fd[READ]);
//		close(fd[WRITE]);
//		execve(cmd2, s2, NULL);
//		exit(EXIT_SUCCESS);
//	}
//	close(fd[READ]);
//	close(fd[WRITE]);
//	waitpid(pid, &status, 0);
//	waitpid(pid2, &status2, 0);
//}