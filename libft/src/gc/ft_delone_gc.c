/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:04:34 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/18 10:04:35 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_delone_gc(void *target, t_gc **gc)
{
	t_gc	*temp;
	int		i;

	i = 0;
	temp = *gc;
	while (temp && temp->content != target)
	{
		i++;
		temp = temp->next;
	}
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
