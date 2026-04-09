/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:02 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/08 15:33:07 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr_gc(char const *s, unsigned int start, size_t len, t_gc	**gc)
{
	char	*new;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		new = ft_calloc_gc(1, 1, gc);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	new = ft_calloc_gc(sizeof(char), (len + 1), gc);
	if (!new)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
