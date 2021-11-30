/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:50:05 by admin             #+#    #+#             */
/*   Updated: 2021/11/30 16:11:41 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "struct.h"
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
** SIGNALS ------------------------------------------------------------------ **
*/

void	sig_handler(int c);
void	quit_process(int c);

/*
** TERMCAPS ----------------------------------------------------------------- **
*/

int		init_env(char **env);
char	*find_env(t_env *env, char *name);
void	free_env(void);
char	*print_prompt(void);
void	free_commands(void);

/*
** PARSING ------------------------------------------------------------------ **
*/

void	parsing(void);
char	*replace_env(char *str, int pos_dollar);
void	split_minishell(char *command);
int		is_in_str(char *s, char c);
int		is_in_quote(char *s, int pos);
int		is_escaped(char *s, int pos);
int		get_token_type(void);
int		is_valid_env_var(char *s);
int		have_error(t_token *token);
void	add_token(t_token **start, t_token *new);
void	free_token(void);
t_token	*create_token(int i);
t_token	*create_token2(char *word, int type);
int		parse_token3(t_token **token, t_cmd *cmd);
void	parse_token(t_token	**token);
void	set_env(char *env, char *value);
void	redirect(t_cmd *cmd);
char	*handle_quotes(char *src, int env);
char	*replace_env2(char *str, int *i);
int		env_size(char *src, int i);
t_env	*lst_new_env(char *name, char *value, int show, int show2);
void	add_env(t_env **alst, t_env *new);
t_env	*get_env(t_env *env, char *name);
t_env	*get_env2(t_env *env, char *name);
void	free_all(void);
int		tokens_list_size(t_token *token);
int		is_builtin(char *s);
t_token	*create_token(int i);
char	*simple_quotes(char *src, int *i);
int		quote_size(char *src, int type, int env);
t_token	*redirect3(t_token *args, t_token **start);
/*
** BUILTINS ----------------------------------------------------------------- **
*/

void	echo_builtin(t_cmd *cmd, int fd);
void	env_builtin(t_token *args, int fd);
void	cd_builtin(t_cmd *cmd);
void	pwd_builtin(t_cmd *cmd);
void	unset_builtin(t_cmd *cmd);
void	export_builtin(t_cmd *cmd);
void	exit_builtin(t_cmd *cmd);
int		lstsize(t_env *l);
int		lstfind_pos(t_env *lst, char *name);

/*
** EXECUTION ---------------------------------------------------------------- **
*/

void	exec_start(void);
void	exec_pipe(t_cmd *cmd);
void	exec_binary(t_cmd *cmd, int pipe1[2], int pipe2[2]);
int		edit_args(t_cmd *cmd);
char	**list_to_tab(t_cmd *cmd);
char	*check_path(t_cmd *cmd);
void	status_child(t_cmd *cmd, int status);
char	*find_binary(t_cmd *cmd, int show);
int		find_all_binary(t_cmd *cmd);
void	heredoc(t_cmd *cmd, t_token **token);
void	handle_fds(t_cmd *cmd, int pipe1[2], int pipe2[2]);
void	execute2(t_cmd *cmd);
void	execute(t_cmd *cmd);
void	close_all(int pipe1[2], int pipe2[2]);
void	checkkkkk(t_token **args);
void	hd_signal(int c);
int		get_next_line(int fd, char **line);
void	add_cmd_env(t_cmd *cmd);
void	test(t_cmd *cmd);
void	export_x(int fd);
/*
** ERROR -------------------------------------------------------------------- **
*/

void	error(char *message, char *cmd, char *arg, int status);

#endif