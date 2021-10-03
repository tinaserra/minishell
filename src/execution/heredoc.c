/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:51:46 by jode-vri          #+#    #+#             */
/*   Updated: 2021/10/03 15:11:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		write(2, "> ", 2);
		if (ft_get_next_line(0, &tmp) && ft_strcmp((*token)->next->word, tmp) != 0)
		{
			if (is_in_str(tmp, '$'))
				tmp = replace_env(tmp, ft_find_in_str(tmp, '$'));
			line = ft_strjoin_free(line, tmp, 'L');
			line = ft_strjoin_free(line, "\n", 'L');
		}
	}
	free(tmp);
	ft_putstr_fd(line, fd[1]);
	free(line);
	close(fd[1]);
}