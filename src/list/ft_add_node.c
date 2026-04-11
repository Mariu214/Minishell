/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:53:05 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/09 15:45:00 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_node(t_lexst **list, void *content, t_token type, t_gc **gc)
{
	t_lexst	*new;

	new = ft_malloc_gc(sizeof(t_lexst), 1, gc);
	if (!new)
		return (1);
	new->content = content;
	new->type = type; 
	new->previous = *list;
	new->next = NULL;
	if (*list)
		(*list)->next = new;
	*list = new;
	return (0);
}