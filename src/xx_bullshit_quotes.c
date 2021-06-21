// #include "minishell.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <term.h>

// 					 0000 0001 & 0000 0010
	// savoir si une chaine est entre simple quote ou double quote

	// "......'$HOME'"	-> contenu
	// "..'..." '$HOME'	-> $HOME
	// "......'" $HOME	-> contenu
	// '......"$HOME"'	-> $HOME

	// parcoure la chaine et si " la plus grosse boite c'est " si le $ et dedans

	// if (str[i] == '"' && !(ms->mask & SIMPLE_Q))// on une double quote en premier

char	*ft_strcdup(char *str, int c)
{
	int i;
	int j;
	int len;
	char	*out;

	i = 0;
	while (str[i] != c)
		i++;
	i++;
	len = 0;
	while (str[i + len] != c)
		len++;
	if ((out = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	j = 0;
	while (str[i] && j < len)
	{
		out[j] = str[i];
		j++;
		i++;
	}
	out[j] = '\0';
	return (out);
}


int		main()
{
	char str[17];
	char *out;

	// str = "   lolo"......'$HOME'"lolo   ";
	str[0] = 'A';
	str[1] = 'A';
	str[2] = '"';
	str[3] = '.';
	str[4] = '.';
	str[5] = '.';
	str[6] = '\'';
	str[7] = '$';
	str[8] = 'H';
	str[9] = 'O';
	str[10] = 'M';
	str[11] = 'E';
	str[12] = '\'';
	str[13] = '"';
	str[14] = 'B';
	str[15] = '.';
	str[16] = '\0';

	printf("str = |%s|\n", str);
	out = ft_strcdup(str, '"');
	printf("out = %s\n", out);
}