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
# include <dirent.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>


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

typedef enum		e_type{
	POINT_V,
	PIPE,
	REDIR,
	ENV,
	NEWL,
	TXT
}					t_type;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;


typedef struct		s_token
{
	char			*word;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct		s_cmd
{
	char			*cmd;
	t_token			*args;
	t_list			*env;
	int				type;
	int				in;
	int				out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

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
	t_list			*history;
	int				history_pos;
	int				cursor_pos;
	char			*line;
	char			*curdir;
	t_list			*commands;
	t_token			*tokens;
	struct s_cmd	*cmds;
	t_env			*env;
	char			*term;
	int				count;
	int				exit;
}					t_minishell;
t_minishell *g_ms;

/*
** SIGNALS ------------------------------------------------------------------ **
*/

void	sig_handler(int c);

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
char	*print_prompt(void);
void	redraw_prompt(char *s);
void	free_commands(void);

/*
** PARSING ------------------------------------------------------------------ **
*/

void	fonction();
void	parsing();
int		get_env_content(char *line, char **env_content);
char	*replace_env(char *str, int pos_dollar);
void	split_minishell(char *command);
int		is_in_str(char *s, char c);
int 	is_in_quote(char *s, int pos);
int		is_escaped(char *s, int pos);
int		get_token_type(void);
int		is_valid_env_var(char *s);
int		have_error(t_token *token);
void	add_token(t_token **start, t_token *new);
void	free_token(void);
t_token	*create_token(int i);
t_token	*create_token2(char *word, int type);
t_token	*create_token3(char *s, int type);
void	add_list(t_cmd **begin, t_cmd *new);
int		parse_token2(t_token **token, t_cmd *cmd);
void	parse_token(t_token	**token);
void	set_env(char* env, char *value);
void	redirect(t_cmd *cmd);
void	exec_cmds(void);
char	*handle_quotes(char *src, int env);
char	*replace_env2(char *str, int *i);
int		env_size(char *src, int i);

/*
** BUILTINS ----------------------------------------------------------------- **
*/

void	echo_builtin(t_token *args, int fd);
void	env_builtin(int fd);
void	cd_builtin(t_cmd *cmd);
void	pwd_builtin(void);

/*
** EXECUTION ---------------------------------------------------------------- **
*/

int		start_command(t_cmd *cmd);
int		print_error(char *str);
char	**list_to_tab(t_cmd *cmd);
int		create_pipe(t_cmd *cmd);

#endif