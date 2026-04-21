/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:53:07 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/21 15:54:19 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_list(t_lexst **gc)
{
	t_lexst	*temp;
	t_lexst	*tp;

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