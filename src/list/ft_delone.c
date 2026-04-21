/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:07:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/21 10:59:42 by malaimo          ###   ########.fr       */
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
		*target = temp->next;
	if (temp->next)
		temp->next->previous = temp->previous;
	if (temp->content)
		ft_delone_gc(temp->content, &data->gc);
	ft_delone_gc(temp, &data->gc);
	return (0);
}
