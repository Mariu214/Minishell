/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:27:40 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/20 16:59:19 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
