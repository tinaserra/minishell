#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	if (fd && c)
		write(fd, &c, 1);
}
