#include "../../include/libft.h"

char	*ft_strdup_gc(const char *s, t_gc **gc)
{
	char	*dest;
	size_t	len_s;

	len_s = ft_strlen(s);
	dest = ft_calloc_gc((len_s + 1), sizeof(char), gc);
	if (!dest)
		return (NULL);
	dest[len_s] = '\0';
	while (len_s--)
		dest[len_s] = s[len_s];
	return (dest);
}
