/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:07:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 12:56:29 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_delone(t_data *data, t_lexst **target)
{
	t_lexst	*temp;

	temp = *target;
	if (!temp)
		return (1);
	if (temp->previous)
		temp->previous->next = temp->next;
	else
	{
		if (temp->next)
			*target = temp->next;
	}
	if (temp->next)
		temp->next->previous = temp->previous;
	else 
		*target = temp->previous;
	if (temp->content)
		ft_delone_gc(temp->content, &data->gc);
	ft_delone_gc(temp, &data->gc);
	return (0);
}
