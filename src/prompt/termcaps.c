#include "minishell.h"

void	set_raw()
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

int		termputs(int c)
{
	return (write(1, &c, 1));
}

void	print_term(char *c)
{
	c = tgetstr(c, NULL);
	tputs(c, 1, termputs);
}

void	redraw_prompt(char *s)
{
	ft_putstr_fd(1, "\r"); // reset la ligne
	print_term("cd"); //clear la ligne avant de reafficher
	print_prompt();
	ft_putstr_fd(1, s);
}

void	print_char(long c)
{
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	if (g_ms->line)
		g_ms->line = ft_strjoin_free(g_ms->line, s, 'L');
	else
		g_ms->line = ft_strdup(s);
	g_ms->cursor++;
}

int		handle_termcaps(long c)
{
	if (c >= 32 && c <= 126)
	{
		print_char(c);
		write(1, &c, 1);
	}
	else if (c == 4283163 || c == 4348699)
		set_history(c);
	else if (c == 127 && g_ms->cursor > 0)
	{
		g_ms->line = ft_del_last_char(g_ms->line);
		redraw_prompt(g_ms->line);
	}
	else if (c == 10)
	{
		add_history(g_ms->line);
		write(1, "\n", 1);
		g_ms->cursor = 0;
		if (g_ms->line)
			parsing();
		free(g_ms->line);
		g_ms->line = NULL;
		print_prompt();
	}
	return (1);
}