#include "minishell.h"

void	set_raw()
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	ms->ce = tgetstr("ce", NULL);
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
	int i;

	i = -1;
	ft_putstr_fd(1, "\r"); //remettre curseur au debut de la ligne
	print_term("cd"); //clear la ligne avant de reafficher
	print_prompt();
	while (++i < (ft_strlen(s)))
		ft_putchar_fd(s[i], 1);
}

void	print_char(long c)
{
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	if (ms->line)
		ms->line = ft_strjoin_free(ms->line, s, 'L');
	else
		ms->line = ft_strdup(s);
	ms->cursor++;
}

int		handle_termcaps(long c)
{
	if (c >= 32 && c <= 126)
	{
		print_char(c);
		write(1, &c, 1);
	}
	else if (c == 4283163) //history up
		set_history(c, &ms->line);
	else if (c == 4348699)
		set_history(c, &ms->line);
	else if (c == 127 && ms->cursor > 0)
	{
		ms->line = ft_del_last_char(ms->line);
		//printf("\n[%s]\n", ms->line);
		redraw_prompt(ms->line);
	}
	//printf("%s\n", ms->line);
	return (1);
}