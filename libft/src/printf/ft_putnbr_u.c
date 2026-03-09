/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:03:22 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 13:49:36 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putnbr_u(unsigned int i)
{
	static int	k;
	int			j;

	k = 0;
	if (i >= 10)
		ft_putnbr_u(i / 10);
	j = ft_putchar ((i % 10) + '0');
	if (j == -1)
		return (-1);
	k += j;
	return (k);
}
