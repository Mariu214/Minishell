/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:36:38 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:38:08 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstadd_gc(t_gc **gc, void *content)
{
	t_gc	*new;

	new = malloc(sizeof(t_gc));
	if (!new)
		return (1);
	new->content = content;
	new->previous = NULL;
	new->next = *gc;
	if (*gc)
		(*gc)->previous = new;
	*gc = new;
	return (0);
}
