#ifndef	MINISHELL_H
#define MINISHELL_H

/*
** HEADERS ------------------------------------------------------------------ **
*/

# include "libft.h"

/*
** LIBRARIES ---------------------------------------------------------------- **
*/

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>

typedef struct  s_minishell
{
    int         close_signal;
    char        *line;
}               t_minishell;
t_minishell	ms;

/*
** SIGNALS ------------------------------------------------------------------ **
*/
void	sig_quit(int c);
void	sig_int(int c);

void fonction();
#endif