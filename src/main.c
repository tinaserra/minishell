#include "minishell.h"

int		main(int ac, char **av, char **path)
{
	(void)ac;
	(void)av;
	(void)path;
	int			ret;
	char		c;

	ft_putstr_fd(1, "\x1B[34mminishell-0.1$>\x1B[0m ");
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	ret = 1;
	while (1)
	{
		while ((ret = read(0, &c, 1)) != 0)
		{
			free(ms.line);
			ms.line = ft_realloc(ms.line, ft_strlen(ms.line) + 1);
			if (c == 10)
				break;
			else
				ms.line[ft_strlen(ms.line)] = c;
		}
		if (ret == 0)
		{
			ft_putstr_fd(1, "exit\n");
			break;
		}
		printf("%s\n", ms.line);
		if (ms.line)
			fonction();
		ft_bzero(ms.line, ft_strlen(ms.line));
		ft_putstr_fd(1, "\x1B[34mminishell-0.1$>\x1B[0m ");
	}
}