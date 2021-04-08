#include "libft.h"

t_list	*ft_lst_find_pos(t_list *lst, int pos)
{
	int i;

	i = 0;
	while (lst)
	{
		if (i == pos)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
