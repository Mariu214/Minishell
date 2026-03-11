/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:01:59 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:38:35 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc_gc(size_t nmemb, size_t size, t_gc **gc)
{
	void			*tab;
	long int		n2;
	long int		s2;

	n2 = (long int)nmemb;
	s2 = (long int)size;
	if ((nmemb > SIZE_MAX / size) || (n2 < 0 && s2 < 0))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	if (ft_lstadd_gc(gc, tab))
	{
		free(tab);
		return (0);
	}
	return (tab);
}
