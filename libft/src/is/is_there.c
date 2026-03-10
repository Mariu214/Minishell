/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:08:12 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 10:14:42 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	is_there(const char str, char *start)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if (str == start[i])
			return (1);
		i++;
	}
	return (0);
}
