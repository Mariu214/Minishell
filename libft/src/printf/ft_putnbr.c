/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:21:26 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 13:49:41 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putnbr(int i)
{
	static int	k;
	int			neg;

	neg = 0;
	k = 0;
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (i < 0)
	{
		neg++;
		if (write(1, "-", 1) == -1)
			return (-1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	if (neg != 0)
		k++;
	if (ft_putchar((i % 10) + '0') == -1)
		return (-1);
	k++;
	return (k);
}
