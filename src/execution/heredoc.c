/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:51:46 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/11 13:09:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_2(char *tmp, char *line, int fd[2])
{
	free(tmp);
	ft_putstr_fd(line, fd[1]);
	free(line);
	close(fd[1]);
}

void	heredoc(t_cmd *cmd, t_token **token)
{
	char	*line;
	char	*tmp;
	int		fd[2];

	pipe(fd);
	cmd->in = fd[0];
	tmp = NULL;
	line = ft_strdup("");
	(*token)->next->word = handle_quotes((*token)->next->word, 0);
	while (!tmp || ft_strcmp((*token)->next->word, tmp) != 0)
	{
		free(tmp);
		tmp = NULL;
		tmp = readline("> ");
		if (tmp && ft_strcmp((*token)->next->word, tmp) != 0)
		{
			if (is_in_str(tmp, '$'))
				tmp = replace_env(tmp, ft_find_in_str(tmp, '$'));
			line = ft_strjoin_free(line, tmp, 'L');
			line = ft_strjoin_free(line, "\n", 'L');
		}
	}
	hd_2(tmp, line, fd);
}
