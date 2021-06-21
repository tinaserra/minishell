/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:50:14 by jode-vri          #+#    #+#             */
/*   Updated: 2021/06/21 13:54:24 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFERSIZE 8192

static int	is_end_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*get_tmp(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	res = malloc(ft_strlen(s) - i + 1);
	if (res == NULL)
		return (NULL);
	i++;
	j = 0;
	while (s && s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

static int	check_params(int fd, char **line, char *buffer)
{
	if (fd < 0 || !line)
		return (-1);
	buffer = malloc(BUFFERSIZE + 1);
	if (buffer == NULL)
		return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buffer;
	int			ret;

	ret = check_params(fd, line, buffer);
	if (ret == -1)
		return (-1);
	ret = 1;
	while (!is_end_line(tmp) && ret != 0)
	{
		ret = read(fd, buffer, BUFFERSIZE);
		if (ret == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret] = '\0';
		tmp = ft_strjoin_free(tmp, buffer, 'L');
	}
	free(buffer);
	*line = get_line(tmp);
	tmp = get_tmp(tmp);
	if (ret == 0)
		return (0);
	else
		return (1);
}
