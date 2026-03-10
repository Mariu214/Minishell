/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:59:37 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:42:16 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*nono;
	char	nini;

	nini = (char)c;
	nono = NULL;
	while (*s)
	{
		if (*s == nini)
			nono = (char *)s;
		s++;
	}
	if (nono != NULL)
		return (nono);
	if (nini == '\0')
		return ((char *)s);
	return (NULL);
}
