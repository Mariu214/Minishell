/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:25:41 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:42:11 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < n)
	{
		while (big[i + j] == little[j] && little[j] && i + j < n)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
