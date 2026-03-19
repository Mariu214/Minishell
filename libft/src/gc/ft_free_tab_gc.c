/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_gc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:14:32 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 12:29:02 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_free_tab_gc(char **tab, t_gc **gc)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_delone_gc(tab[i], gc);
		i++;
	}
	ft_delone_gc(tab, gc);
}
