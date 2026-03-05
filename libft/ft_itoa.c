/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:17:33 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/18 16:14:43 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char		*nbr;
	long int	len;
	long int	m;

	m = (long int)n;
	len = 0;
	len = size(m);
	nbr = malloc(sizeof(char) * len + 1);
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
