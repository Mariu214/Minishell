/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:04:47 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/19 11:35:26 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len_s;

	len_s = ft_strlen(s);
	dest = malloc(sizeof(char) * (len_s + 1));
	if (!dest)
		return (NULL);
	dest[len_s] = '\0';
	while (len_s--)
		dest[len_s] = s[len_s];
	return (dest);
}
