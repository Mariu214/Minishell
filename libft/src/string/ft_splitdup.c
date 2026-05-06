/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:02:47 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:24:19 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_splitdup(char **str)
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
	cpy[i] = NULL;
	return (cpy);
}
