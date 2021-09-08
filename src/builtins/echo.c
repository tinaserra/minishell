#include "minishell.h"

int	echo_new_line(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (0);
	return (1);
}

void	echo_builtin(t_token *args, int fd)
{
	int		nl;
	t_token	*tmp;

	tmp = args;
	if (fd == 0)
		fd = 1;
	if (!tmp)
		return ;
	nl = echo_new_line(tmp->word);
	if (nl == 0)
		tmp = tmp->next;
	while (tmp)
	{
		ft_putstr_fd(tmp->word, fd);
		if (tmp->next)
			ft_putchar_fd(' ', fd);
		else if (nl)
			ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
