/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:28 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/01 14:57:29 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	lst_add_node(t_lexst **list, char *content, int type)
{
	t_lexst *new;

	new = malloc(sizeof(t_lexst));
	if (!new)
		return (1);
	new->content = content;
    new->type = type;
	new->previous = NULL;
	new->next = *list;
	if (*list)
		(*list)->previous = new;
	*list = new;
	return (0);
}