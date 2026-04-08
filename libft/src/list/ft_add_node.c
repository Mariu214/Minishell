/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:53:05 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/01 14:53:28 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstadd_gc(t_list **gc, void *content)
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