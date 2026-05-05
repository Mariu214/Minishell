/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:08:18 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/05 11:03:33 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_renew_gc(char *start, char *end, int mode, t_gc **gc)
{
	char	*temp;

	if (!gc)
		return (NULL);
	if (!start || !end)
	{
		if (start)
			return (start);
		if (end)
			return (end);
		return (NULL);
	}
	temp = ft_strjoin_gc(start, end, gc);
	if (mode == 0)
		ft_delone_gc(start, gc);
	else if (mode == 1)
		ft_delone_gc(end, gc);
	else
	{
		ft_delone_gc(start, gc);
		ft_delone_gc(end, gc);
	}
	return (temp);
}
