/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_gc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:53:27 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/27 14:26:06 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_free_all_gc(t_gc **gc)
{
	t_gc	*temp;
	t_gc	*tp;

	if (!*gc)
		return;
	temp = (*gc);
	while (temp)
	{
		tp = temp->next;
		if (temp->content)
			free(temp->content);
		if (temp)
			free(temp);
		temp = tp;
	}
	*gc = NULL;
}
