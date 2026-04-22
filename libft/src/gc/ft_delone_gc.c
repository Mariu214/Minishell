/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:07:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 15:08:20 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_delone_gc(void *target, t_gc **gc)
{
	t_gc	*temp;

	temp = *gc;
	while (temp && temp->content != target)
		temp = temp->next;
	if (!temp)
		return (1);
	if (temp->previous)
		temp->previous->next = temp->next;
	else
		*gc = temp->next;
	if (temp->next)
		temp->next->previous = temp->previous;
	if (temp->content)
		free(temp->content);
	free(temp);
	return (0);
}
