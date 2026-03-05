/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:15:33 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/18 17:31:09 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*ss1;
	size_t			i;

	if (n == 0)
		return (NULL);
	ss1 = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (ss1[i] == (unsigned char)c)
			return ((void *)(ss1 + i));
		i++;
	}
	return (NULL);
}
