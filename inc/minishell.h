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
# include <sys/ioctl.h>
# include <term.h>

/*
** VALUES ------------------------------------------------------------------- **
*/

# define IS_ECHO	1 << 0
# define IS_NL		1 << 1
# define IS_CD		1 << 2
# define IS_PWD		1 << 3
# define IS_EXPORT	1 << 4
# define IS_UNSET	1 << 5
# define IS_ENV		1 << 6
# define IS_EXIT	1 << 7

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

//typedef struct	s_data
//{
//	char			mask;
//}				t_data;

typedef struct		s_minishell
{
	int				close_signal;
	unsigned char	*line;
	char			***cmds;
	char			mask;
	t_env			*env;
}					t_minishell;
t_minishell *ms;

/*
** SIGNALS ------------------------------------------------------------------ **
*/

void	sig_quit(int c);
void	sig_int(int c);

int	    init_env(char **env);
char	*find_env(t_env *env, char *name);
void	print_prompt();
void    fonction();
#endif