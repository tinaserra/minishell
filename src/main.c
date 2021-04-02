#include "minishell.h"

char	*ft_strcpy()

char	*ft_realloc(char **line, char c)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(*line);
	tmp = malloc(len + 1);
	i = -1;
	ft_strcpy();

}

int		main(int ac, char **av, char **path)
{
	(void)ac;
	(void)av;
	(void)path;
	int		ret;
	char	c;
	char	*line;

	//fonction();
	ft_putstr_fd(1, "\x1B[34mminishell-0.1$>\x1B[0m ");
	ret = 1;
	while ((ret = read(0, &c, 1)) != 0)
	{
		line = ft_realloc(&line, c);
	}
}