/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:04:47 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 14:59:55 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

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
