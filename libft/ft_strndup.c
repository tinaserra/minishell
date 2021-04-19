#include "libft.h"

char	*ft_strndup(char *s1, size_t len)
{
	char	*out;
	size_t	i;

	i = -1;
	if ((out = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (s1[++i] && i < len)
		out[i] = s1[i];
	out[i] = '\0';
	return (out);
}