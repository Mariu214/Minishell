/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:59:37 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/19 10:12:31 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
