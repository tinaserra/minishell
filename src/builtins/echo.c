#include "minishell.h"

int	echo_new_line(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (0);
	return (1);
}

void	echo_builtin()
{
	// size_t	i;
	// int		nl;
	// t_list	*tmp;

	// i = -1;
	// tmp = cmds->cmds_list;
	// if ((nl = echo_new_line(tmp->data)) == 0)
	// 	tmp = tmp->next;
	// while (tmp)
	// {
	// 	ft_putstr_fd(1, tmp->data);
	// 	if (tmp->next)
	// 		ft_putchar_fd(' ', 1);
	// 	else if (nl)
	// 		ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
	// }
}