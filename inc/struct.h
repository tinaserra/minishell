/*
** ERRORS ------------------------------------------------------------------- **
*/

typedef enum		e_error{
	SYNTXT,
	HOME,
	NUMBER
}					t_error;

/*
** TYPE --------------------------------------------------------------------- **
*/

typedef enum		e_type{
	POINT_V,
	PIPE,
	REDIR,
	ENV,
	NEWL,
	TXT
}					t_type;

/*
** STRUCT ------------------------------------------------------------------- **
*/

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