/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:51:46 by jode-vri          #+#    #+#             */
/*   Updated: 2021/09/27 07:57:48 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_cmd *cmd, t_token **token)
{
	char	*line;
	char	*tmp;
	int		fd[2];
	//int		tmp1;

	pipe(fd);
	cmd->in = fd[0];
	//tmp1 = 0;
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
			line = ft_strjoin_free(line, tmp, 'L');
			line = ft_strjoin_free(line, "\n", 'L');
		}
	}
	free(tmp);
	//if (is_in_str(line, '$'))
	//	line = replace_env2(line, 0);
	ft_putstr_fd(line, fd[1]);
	free(line);
	close(fd[1]);
}