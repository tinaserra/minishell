#ifndef	MINISHELL_H
#define MINISHELL_H

/*
** HEADERS ------------------------------------------------------------------ **
*/

# include "libft.h"
# include "struct.h"

/*
** LIBRARIES ---------------------------------------------------------------- **
*/

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/errno.h>


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

//# define DOUBLE_Q	1 << 0 // -> 0000 0001
//# define SIMPLE_Q	1 << 1 // -> 0000 0010

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
char	*handle_quotes(char *src, int env);
char	*replace_env2(char *str, int *i);
int		env_size(char *src, int i);
t_env	*lst_new_env(char *name, char *value);
void	add_env(t_env **alst, t_env *new);
t_env	*get_env(t_env *env, char *name);
t_env	*get_env2(t_env *env, char *name);
void	unset_builtin(t_cmd *cmd);
t_env	*env_free_at(t_env *l, int pos);
void	free_all();

/*
** BUILTINS ----------------------------------------------------------------- **
*/

void	echo_builtin(t_token *args, int fd);
void	env_builtin(int fd);
void	cd_builtin(t_cmd *cmd);
void	pwd_builtin(void);
void	export_builtin(t_cmd *cmd);

/*
** EXECUTION ---------------------------------------------------------------- **
*/

void	exec_start(void);
void	exec_pipe(char *cmd, char *cmd2, char **s1, char **s2);
void	edit_args(t_cmd *cmd);
int		lst_size(t_cmd *cmd);
char	**list_to_tab(t_cmd *cmd);
char	*check_path(t_cmd *cmd);
char	**list_to_tab(t_cmd *cmd);

/*
** ERROR -------------------------------------------------------------------- **
*/

int		print_error(int error);
void	printerrno_fd(int fd, char *cmd, char *arg);

#endif