#include "minishell.h"

int	echo_new_line(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (0);
	return (1);
}

int	echo_code_error(char *s)
{
	if (ft_strcmp(s, "$?") == 0)
		return (1);
	return (0);
}

void	echo_builtin(t_token *args, int fd)
{
	int		nl;
	int		coderr;
	t_token	*tmp;

	tmp = args;
	if (fd == 0)
		fd = 1;
	if (!tmp)
		return ;
	nl = echo_new_line(tmp->word);
	coderr = echo_new_line(tmp->word);
	if (coderr == 1)
		printf("GROSSE TCHOIN\n");
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
