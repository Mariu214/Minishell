#include "../../include/libft.h"

void	ft_free_all_gc(t_gc **gc, int index)
{
	t_gc	*temp;
	t_gc	*tp;

	temp = (*gc);
	while (temp)
	{
		tp = temp->next;
		if (temp->content)
			free(temp->content);
		free(temp);
		temp = tp;
	}
	*gc = NULL;
	exit(0);
}