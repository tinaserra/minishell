#include "minishell.h"

void	sig_handler(int c)
{
	//if (c == 3) // backslash
	//	free_all();
	if (c == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
