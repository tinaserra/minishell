#include "minishell.h"

void	sig_quit(int c)
{
	(void)c;
	if (g_ms->line)
	{
		free(g_ms->line);
		g_ms->line = NULL;
	}
	print_prompt();
}

void	sig_int(int c)
{
	(void)c;
	if (g_ms->line)
	{
		free(g_ms->line);
		g_ms->line = NULL;
	}
	ft_putstr_fd("\n", 1);
	print_prompt();
}
