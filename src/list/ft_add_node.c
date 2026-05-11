/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:53:05 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 14:57:36 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_node(t_lexst **list, void *content, t_token token, t_gc **gc)
{
	t_lexst	*new;

	new = ft_malloc_gc(sizeof(t_lexst), 1, gc);
	if (!new)
		return (1);
	new->content = content;
	new->type = token.type;
	new->word_type = token.quote;
	new->previous = *list;
	new->next = NULL;
	if (*list)
		(*list)->next = new;
	*list = new;
	return (0);
}
