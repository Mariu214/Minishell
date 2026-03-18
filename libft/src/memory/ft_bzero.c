/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:32:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 10:05:24 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			m;

	if (!s)
		return ;
	t = (unsigned char *)s;
	m = 0;
	while (m < n)
	{
		t[m] = '\0';
		m++;
	}
}
