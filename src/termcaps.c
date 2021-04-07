#include "minishell.h"

void	set_raw()
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

int termputs(int c)
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
	int i;

	i = -1;
	ft_putstr_fd(1, "\r");
	print_term("cd");
	print_prompt();
	while (++i < (ft_strlen(s)))
		ft_putchar_fd(s[i], 1);
}

int		handle_termcaps(t_minishell *ms, char c)
{
	if (c == CTRL_D)
	{
		ft_putstr_fd(1, "exit\n");
		return (-1);
	}
	if (c == KEY_DEL && ms->cursor > 0)
	{
		ms->cursor--;
		ms->line[ft_strlen((char *)ms->line) - 1] = '\0';
		redraw_prompt((char *)ms->line);
	}
	else if (c == KEY_DOWN || c == KEY_UP)
	{
		//history
	}
	return (1);
}