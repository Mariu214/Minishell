/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:27:40 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 15:01:03 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tp;

	if (!(*lst) || !del)
		return ;
	temp = (*lst);
	while (temp)
	{
		tp = temp->next;
		ft_lstdelone(temp, del);
		temp = tp;
	}
	(*lst) = NULL;
}
