/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:37:05 by jdelmott          #+#    #+#             */
/*   Updated: 2025/12/15 13:59:10 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print(unsigned long i)
{
	char		*base;
	static int	k;
	int			j;

	k = 0;
	base = "0123456789abcdef";
	if (i > 15)
		ft_print(i / 16);
	j = ft_putchar(base[i % 16]);
	if (j == -1)
		return (-1);
	k += j;
	return (k);
}

int	ft_putnbr_p(unsigned long s)
{
	if (s == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_print(s) + 2);
}
