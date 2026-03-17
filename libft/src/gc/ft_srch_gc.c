#include "../../include/libft.h"

int	ft_srch_gc(t_gc **gc, void *target)
{
	int	i;

	i = 0;
	if (!target || !gc || !(*gc))
		return (-1);
	while ((*gc) && (*gc)->content != target)
	{
		*gc = (*gc)->next;
		i++;
	}
	if (!(*gc))
		return (-1);
	return (i);
}