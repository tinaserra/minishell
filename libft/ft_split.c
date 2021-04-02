/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 11:25:35 by jode-vri          #+#    #+#             */
/*   Updated: 2021/02/25 17:19:05 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_charset(char c, char *charset)
{
	while (charset && *charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		count_nb_word(char *str, char *charset)
{
	int count;
	int is_word;

	count = 0;
	is_word = 0;
	while (str && *str)
	{
		if (is_charset(*str, charset))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		str_size(char *str, char *charset, int pos)
{
	int i;

	i = 0;
	while (str && str[pos])
	{
		if (!is_charset(str[pos], charset))
			i++;
		pos++;
	}
	return (i);
}

void	ft_split2(char **tab, char *str, char *charset)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	while (str && str[++i])
	{
		if (!is_charset(str[i], charset))
		{
			if (k == 0)
				if ((tab[j] = malloc(sizeof(char *) * (str_size(str, charset, i)
					+ 1))) == NULL)
					return ;
			tab[j][k] = str[i];
			tab[j][k + 1] = '\0';
			k++;
		}
		if ((is_charset(str[i], charset) && !is_charset(str[i + 1], charset)
				&& k > 0) && (k = 0) == 0)
			j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	if ((result = malloc(sizeof(char *) *
			(count_nb_word(str, charset) + 1))) == NULL)
		return (NULL);
	ft_split2(result, str, charset);
	result[count_nb_word(str, charset)] = 0;
	return (result);
}
