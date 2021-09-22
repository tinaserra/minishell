#include "minishell.h"

void	sig_handler(int c)
{
	if (c == 3 && g_ms->fork) // backslash
		printf("Quit\n");
	if (c == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
