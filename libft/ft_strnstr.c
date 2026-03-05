/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:25:41 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:35 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const unsigned char	*b;
	const unsigned char	*l;
	size_t				i;
	size_t				j;

	b = (const unsigned char *)big;
	l = (const unsigned char *)little;
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
