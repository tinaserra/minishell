#include "minishell.h"

int		main(int ac, char **av, char **path)
{
	(void)ac;
	(void)av;
	(void)path;
	int		ret;
	char	c;
	char	*line;


	ms.close_signal = 1;
	ft_putstr_fd(1, "\x1B[34mminishell-0.1$>\x1B[0m ");
	ret = 1;
	while (ms.close_signal)
	{
		while ((ret = read(0, &c, 1)) != 0)
		{
			free(line);
			line = ft_realloc(line, ft_strlen(line) + 1);
			if (c == 10)
				break;
			else
				line[ft_strlen(line)] = c;
		}
		printf("%s\n", line);
		//fonction();
		ft_bzero(line, ft_strlen(line));
		ft_putstr_fd(1, "\x1B[34mminishell-0.1$>\x1B[0m ");
	}
}