#include "minishell.h"

/**
 * print_prompt
 * * print prompt text
 * @param ms minishell structure
 * @param s executable name
 */

void	print_prompt(t_minishell *ms, char *s)
{
	char	**res;

	res = ft_split(s, "./");
	ft_putstr_fd(1, ms->env.user);
	ft_putstr_fd(1, " ➜ \x1B[34m");
	ft_putstr_fd(1, res[0]);
	ft_putstr_fd(1, "\x1B[0m ");
	free(res);
}

/**
 * read_line
 * * read the line in stdin and put it in ms.line
 * @param ret read return value
 */

void	read_line(int *ret)
{
	char	c;
	int		i;
	
	i = 0;
	while ((*ret = read(0, &c, 1)) != 0)
	{
		ms.line = ft_realloc(ms.line, i + 2);
		if (c == 10)
			break;
		else
		{
			ms.line[i] = c;
			ms.line[i + 1] = '\0';
			i++;
		}
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int		ret;

	signal(SIGINT, &sig_int); 
	signal(SIGQUIT, &sig_quit); 
	init_env(&ms, env);
	ms.line = NULL;
	ret = 1;
	while (1)
	{
		print_prompt(&ms, av[0]);
		read_line(&ret);
		if (ret == 0)
		{
			ft_putstr_fd(1, "exit\n");
			break;
		}
		if (ms.line)
		{
			fonction(&ms); // parsing
			//execute();
		}
		ft_bzero(ms.line, ft_strlen(ms.line));
	}
}