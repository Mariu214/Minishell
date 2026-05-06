/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:50:48 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:57:31 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_node_list(t_lexst **list, t_lexst **temp)
{
	while ((*list)->next)
		(*list) = (*list)->next;
	(*temp)->previous = (*list);
	(*list)->next = (*temp);
	while ((*list)->previous)
		(*list) = (*list)->previous;
	return (0);
}
