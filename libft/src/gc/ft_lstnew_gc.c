/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:36:38 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:38:08 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstnew_gc(t_gc **gc)
{
	*gc = malloc(sizeof(t_gc));
	if (!*gc)
		return (1);
	(*gc)->content = NULL;
	(*gc)->previous = NULL;
	(*gc)->next = NULL;
	return (0);
}