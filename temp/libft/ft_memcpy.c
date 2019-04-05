#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((char*)src)[i])
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}
