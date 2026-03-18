/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:53:19 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/17 14:17:16 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc_gc(size_t nmemb, size_t size, t_gc **gc)
{
	void		*tab;
	long int	n2;
	long int	s2;

	n2 = (long int)nmemb;
	s2 = (long int)size;
	if ((nmemb > SIZE_MAX / size) || (n2 < 0 && s2 < 0))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		ft_free_all_gc(gc);
	ft_bzero(tab, (nmemb * size));
	if (ft_lstadd_gc(gc, tab))
		ft_free_all_gc(gc);
	return (tab);
}
