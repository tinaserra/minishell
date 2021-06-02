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

typedef struct	s_args
{
	char		**args;
}				t_args;

typedef struct	s_cmds // john.c
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
	char			mask;
	int				quote;
	int				close_signal;
	int				cursor;
	int				prompt_size;
	t_list			*history;
	int				history_pos;
	int				cursor_pos;
	char			*line;
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

void	set_raw(void);
int		handle_termcaps(long c);
void	print_term(char *c);
int		termputs(int c);

int		init_env(char **env);
char	*find_env(t_env *env, char *name);
void	free_env(void);
int		get_history(t_minishell *ms);
void	add_history(char *line);
void	set_history(long c);
void	free_history(void);
void	print_prompt();
void	redraw_prompt(char *s);

/*
** PARSING ------------------------------------------------------------------ **
*/
void	fonction();
void	parsing();
int		get_env_content(char *line, char **env_content);
char	*replace_env(char *str, int pos_dollar);

/*
** BUILTINS ----------------------------------------------------------------- **
*/

void	echo_builtin(t_cmds *cmds); // john.c
void	env_builtin();
#endif