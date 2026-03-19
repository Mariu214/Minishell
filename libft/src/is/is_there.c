/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:08:12 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 10:28:51 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	is_there(const char okay, char *look_inside_me)
{
	int	i;

	i = 0;
	while (look_inside_me[i])
	{
		if (okay == look_inside_me[i])
			return (1);
		i++;
	}
	return (0);
}
