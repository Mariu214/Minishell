/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew_one_gc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:06:04 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:22 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_renew_one_gc(char *start, char end, t_gc **gc)
{
	char	*temp;

	if (!start || !end || !gc)
		return (NULL);
	temp = ft_join_one_gc(start, end, gc);
	ft_delone_gc(start, gc);
	return (temp);
}
