#include "libft.h"

void ft_free_tab(char **tab)
{
	int i;

	i = -1;
	while (++i < ft_strs_tab_size(tab))
		free(tab[i]);
}