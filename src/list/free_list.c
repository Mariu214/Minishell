/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:53:07 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/30 10:58:52 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_list(t_lexst **gc, t_gc **g)
{
	t_lexst *temp;
	t_lexst *tp;

	temp = (*gc);
	while (temp)
	{
		tp = temp->next;
		if (temp->content)
			ft_delone_gc(temp->content, g);
		if (temp)
			ft_delone_gc(temp, g);
		temp = tp;
	}
	*gc = NULL;
}