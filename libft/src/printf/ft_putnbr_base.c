/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:39:49 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:39:27 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putnbr_base(unsigned int i, char *base)
{
	static int		k;
	unsigned int	len_base;
	size_t			index;

	k = 0;
	index = 0;
	len_base = (unsigned int)ft_strlen(base);
	if (i >= len_base)
		ft_putnbr_base(i / len_base, base);
	index = (i % len_base);
	k++;
	if (ft_putchar(base[index]) == -1)
		return (-1);
	return (k);
}
