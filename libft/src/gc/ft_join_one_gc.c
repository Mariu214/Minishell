/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_one_gc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:03:30 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:14 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_join_one_gc(char const *s, char const c, t_gc **gc)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	len_s = ft_strlen(s);
	new = ft_calloc_gc((len_s + 2), sizeof(char), gc);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	return (new);
}
