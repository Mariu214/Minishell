#include "../../include/libft.h"

int	ft_delone_gc(t_gc **gc, void *target)
{
	t_gc	*temp;
	t_gc	*next;
	t_gc	*prev;
	int		i;
	int		lim;

	i = 0;
	temp = (*gc);
	lim = ft_srch_gc(gc, target);
	if (!lim)
		return (1);
	while (i++ < lim)
		temp = temp->next;
	next = temp->next;
	prev = temp->previous;
	if (temp->content)
			free(temp->content);
	free(temp);
	temp = prev;
	temp->next = next;
	while((*gc)->previous)
		(*gc) = (*gc)->previous;
	return (0);
}
