/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:02:47 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 14:03:37 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_splitcpy(char **str)
{
	int		i;
	char	**cpy;

	i = 0;
	if (!str)
		return (NULL);
	cpy = ft_calloc(sizeof(char *), (ft_splitlen(str) + 1));
	while (str[i])
	{
		cpy[i] = ft_strdup(str[i]);
		i++;
	}
	return (cpy);
}