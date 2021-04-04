#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	int			ret;
	char		c;

	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	init_env(&ms, env);
	ret = 1;
	while (1)
	{
		ft_putstr_fd(1, "minishell ➜ \x1B[34m");
		ft_putstr_fd(1, ms.env.pwd);
		ft_putstr_fd(1, "\x1B[0m ");
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
			fonction(&ms, env);
		ft_bzero(ms.line, ft_strlen(ms.line));
	}
}