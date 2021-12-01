/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:47:38 by admin             #+#    #+#             */
/*   Updated: 2021/12/01 13:57:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <readline/readline.h>
/*
** ERRORS ------------------------------------------------------------------- **
*/

typedef enum e_error{
	ERRNO = -1,
	SYNTXT,
	HOME,
	EXPORT,
	CMD,
	FORKING,
	PIPING,
	NUMBER
}					t_error;

/*
** TYPE --------------------------------------------------------------------- **
*/

typedef enum e_type{
	POINT_V,
	PIPE,
	REDIR,
	ENV,
	NEWL,
	TXT,
	EXIT_STATUS
}					t_type;

/*
** STRUCT ------------------------------------------------------------------- **
*/

typedef struct s_env
{
	char			*name;
	char			*value;
	int				show;
	int				show2;
	struct s_env	*next;
}					t_env;

typedef struct s_env2
{
	char			*name;
	char			*value;
	int				tmp;
}					t_env2;

typedef struct s_token
{
	char			*word;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	char			*cmd;
	char			*cmd_s;
	char			*bin;
	char			*tmp;
	t_token			*args;
	char			**argss;
	t_list			*env;
	int				type;
	int				in;
	int				out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_minishell
{
	pid_t			pid;
	int				status;
	int				quote;
	int				fork;
	char			*line;
	char			*curdir;
	t_list			*commands;
	t_list			*env_list;
	t_token			*tokens;
	struct s_cmd	*cmds;
	t_env			*env;
	char			*term;
	char			*hd_tmp;
	int				count;
	int				end;
	int				hd_quit;
	int				hd_start;
	char			*hd_line;
	int				newline;
	int				unclosed;
	int				ign_array;
	int				no_cmd_arg;
	rl_getc_func_t	*getc_func;
}					t_minishell;
t_minishell	*g_ms;

#endif