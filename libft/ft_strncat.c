#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;

	i = ft_strlen(s1);
	while (*s2 && n)
	{
		s1[i] = *s2;
		i++;
		s2++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}