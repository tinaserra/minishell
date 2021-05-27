#include "libft.h"

void	ft_lstprint(t_list *l)
{
	if (l == NULL)
		printf("la liste est vide\n");
	while (l != NULL)
	{
		printf("[%s]\n", (char *)l->data);
		l = l->next;
	}
	printf("\n");
}