/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:58:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/07 16:59:52 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static long int	size(long int n)
{
	long int	i;
	long int	len;

	i = (long int)n;
	len = 0;
	if (i <= 0)
	{
		len++;
		i = -i;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_gc(int n, t_gc **gc)
{
	char		*nbr;
	long int	len;
	long int	m;

	m = (long int)n;
	len = 0;
	len = size(m);
	nbr = ft_calloc_gc(sizeof(char), len + 1, gc);
	if (nbr == NULL)
		return (0);
	nbr[len] = '\0';
	if (m == 0)
		nbr[0] = '0';
	if (m < 0)
	{
		nbr[0] = '-';
		m = -m;
	}
	while (m != 0)
	{
		nbr[len - 1] = ((m % 10) + '0');
		m /= 10;
		len--;
	}
	return (nbr);
}
