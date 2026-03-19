/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy_gc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:31:57 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 17:04:09 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_splitcpy_gc(char **str, t_gc **gc)
{
	int i;
	char **cpy;

	i = 0;
	if (!str)
		return (NULL);
	cpy = ft_calloc_gc(sizeof(char *), (ft_splitlen(str) + 1), gc);
	while (str[i])
	{
		cpy[i] = ft_strdup_gc(str[i], gc);
		i++;
	}
	return (cpy);
}