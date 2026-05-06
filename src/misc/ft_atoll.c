/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:22:42 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 10:36:53 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

long	ft_atoll(const char *nptr, t_data *data)
{
	int		signe;
	long   nbr;
	int		i;

	signe = 1;
	nbr = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			ft_shellerror_gc("exit: numeric argument required\n", data, 2, 0);
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * signe);
}
