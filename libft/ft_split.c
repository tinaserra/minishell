/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 02:30:32 by vserra            #+#    #+#             */
/*   Updated: 2019/08/18 00:48:16 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_len_word compte la longueur de chaque mot.
** on check si le separateur n'est pas dansn la chaine, et on incremente len.
** quand on tombe sur un separateur, on arrete de compter
*/

int		ft_len_word(char *str, char *charset)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if ((ft_strchr(charset, str[len]) == NULL))
			len++;
		else
			break ;
	}
	return (len);
}

char	*ft_dup(char *src, char *charset)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = ft_len_word(src, charset);
	if (!(dest = malloc(sizeof(*src) * (len + 1))))
		return (0);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** 1ere condition : le premier mot s'il existe, on compte un mot
** 2eme condition : si le caractere n'est pas un charset
** et que le caractere d'avant est un charset, on compte un mot.
*/

int		ft_count_word(char *str, char *charset)
{
	int		i;
	int		nbr_word;

	i = 0;
	nbr_word = 0;
	while (str[i])
	{
		if ((ft_strchr(charset, str[i]) == NULL) && (i == 0))
		{
			nbr_word++;
			i++;
		}
		if ((ft_strchr(charset, str[i]) == NULL) &&
				(ft_strchr(charset, str[i - 1]) != NULL))
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		nbr_word;

	nbr_word = ft_count_word(str, charset);
	if (!(tab = (char **)malloc(sizeof(char*) * (nbr_word + 1))))
		return (NULL);
	tab[nbr_word] = NULL;
	i = 0;
	while (*str)
	{
		if (ft_strchr(charset, *str) == NULL)
		{
			tab[i] = ft_dup(str, charset);
			i++;
			str += ft_len_word(str, charset);
		}
		else
			str++;
	}
	return (tab);
}
