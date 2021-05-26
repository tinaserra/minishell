#ifndef	MINISHELL_H
#define MINISHELL_H

/*
** HEADERS ------------------------------------------------------------------ **
*/

# include "libft.h"
# include "keycode_ascii.h"

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
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <term.h>

/*
** VALUES ------------------------------------------------------------------- **
*/

// # define IS_ECHO		1 << 0 // -> 0000 0001
// # define IS_NL		1 << 1 // -> 0000 0010
// # define IS_CD		1 << 2 // -> 0000 0100
// # define IS_PWD		1 << 3 // -> 0000 1000
// # define IS_EXPORT	1 << 4
// # define IS_UNSET	1 << 5
// # define IS_ENV		1 << 6
// # define IS_EXIT		1 << 7

# define DOUBLE_Q	1 << 0 // -> 0000 0001
# define SIMPLE_Q	1 << 1 // -> 0000 0010

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

//typedef struct	s_args
//{
//	char			*arg;
//	struct s_args	*next;
//}				t_args;

typedef struct	s_cmds
{
	char		*cmd;
	t_list		*args;
}				t_cmds;



// [echo $HOME bonjour cnecn rfor] ; OK
// [echo '$HOME' cnecn rfor] ;
// [echo bonjour cnecn rfor | cat -e] ;
// [echo bonjour cnecn rfor | cat -e] ;
// [echo bonjour cnecn rfor | cat -e]

	// OR |
	// 0 | 0 = 0
	// 0 | 1 = 1
	// 1 | 0 = 1
	// 1 | 1 = 1

	// XOR ^
	// 0 ^ 0 = 0
	// 0 ^ 1 = 1
	// 1 ^ 0 = 1
	// 1 ^ 1 = 0

typedef struct		s_minishell
{
	char			mask; // -> 0000 0000

	// ms->mask ^= DOUBLE_Q
	// 0 ^ 1 = 1
	// mask -> 0000 0010


	int				fdp;
	int				close_signal;
	int				cursor;
	int				prompt_size;
	t_list			*history;
	int				history_pos;
	int				cursor_pos;
	char			*line;
	char			*key_upp;
	t_list			*commands;
	t_cmds			cmds;
	t_env			*env;
}					t_minishell;
t_minishell *ms;

/*
** SIGNALS ------------------------------------------------------------------ **
*/

void	sig_quit(int c);
void	sig_int(int c);

/*
** TERMCAPS ----------------------------------------------------------------- **
*/

void	set_raw();
int		handle_termcaps(t_minishell *ms, char **line, char c, char d);
void	print_term(char *c);
int		termputs(int c);

int	    init_env(char **env);
char	*find_env(t_env *env, char *name);
int     get_history(t_minishell *ms);
void    add_history(char *line);
void	set_history(char c, char **line);
void	print_prompt();
char	*append_at_pos(char *s, char c, int pos);
void	redraw_prompt(char *s);
void    fonction();

/*
** BUILTINS ---------------------------------------------------------------- **
*/

void	echo_builtin(t_cmds *cmds);
void    env_builtin();
#endif