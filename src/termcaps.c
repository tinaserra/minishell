#include "minishell.h"

void	set_raw()
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	ms->key_upp = tgetstr("ku", NULL);
	//ms->key_upp[1] = '[';
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

char	*append_at_pos(char *s, char c, int pos)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (++i < pos)
		res[i] = s[i];
	res[i] = c;
	while (++i < ft_strlen(s))
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

int		handle_termcaps(t_minishell *ms, char **line, char c, char d)
{
	(void)ms;
	(void)line;
	(void)c;
	(void)d;

	if (c == CTRL_D)
	{
		//if (!*line || ft_strlen(*line) == 0)
			return (ft_putstr_fd(1, "exit\n"));
		
		//return (42);
	}
	if (c == KEY_DEL && ms->cursor > 0)
	{
		(ms->cursor)--;
		*line = ft_del_last_char(*line);
		redraw_prompt(*line);
		return (42);
	}
	//if (d == '[' && (c == 'A' || c == 'D'))
	//{
	//	printf("%d\n", c);
	//	print_term("cd");
	//	set_history(c, line);
	//	return (42);
	//}
	else if (c == KEY_DOWN || c == KEY_UP)
	{
		print_term("cd");
		set_history(c, line);
		return (42);
	}
	return (1);
}