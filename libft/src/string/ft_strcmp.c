/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:28:43 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 10:05:09 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	if (!s1 || !s2)
		return (-1);
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	while (s1[i] == ss2[i] && ss1[i])
		i++;
	return ((int)(ss1[i] - ss2[i]));
}
