/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:21:26 by jdelmott          #+#    #+#             */
/*   Updated: 2026/02/10 14:13:43 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int i, int fd)
{
	static int	k;
	int			neg;

	neg = 0;
	k = 0;
	if (i == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (i < 0)
	{
		neg++;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	if (neg != 0)
		k++;
	if (ft_putchar_fd((i % 10) + '0', fd) == -1)
		return (-1);
	k++;
	return (k);
}
