/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:13 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/17 17:04:14 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ddest;
	unsigned char	*ssrc;
	size_t			i;

	i = 0;
	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (ddest < ssrc || ddest >= ssrc + n)
	{
		while (i < n)
		{
			ddest[i] = ssrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			ddest[n] = ssrc[n];
	}
	return (dest);
}
