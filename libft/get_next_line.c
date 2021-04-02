/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:50:14 by jode-vri          #+#    #+#             */
/*   Updated: 2021/02/25 17:19:28 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_end_line(char *s)
{
	int i;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		length;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = malloc(sizeof(char) * length)))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*get_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
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

char	*get_tmp(char *s)
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
	if (!(res = malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return (NULL);
	i++;
	j = 0;
	while (s && s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*tmp;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (8192 + 1))))
		return (-1);
	ret = 1;
	while (!is_end_line(tmp) && ret != 0)
	{
		if ((ret = read(fd, buffer, 8192)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	*line = get_line(tmp);
	tmp = get_tmp(tmp);
	return (ret == 0 ? 0 : 1);
}