/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:55:26 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 14:59:47 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i++;
	}
	if (c2 == '\0')
		return ((char *)s + i);
	return (NULL);
}
