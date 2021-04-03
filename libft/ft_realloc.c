#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	res = malloc(size);
	ft_memcpy(res, ptr, size);
	return (res);
}
