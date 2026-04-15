/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:08:18 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/15 10:49:31 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_renew_gc(char *start, char *end, int mode, t_gc **gc)
{
	char	*temp;

	if (!start || !end || !gc)
		return (NULL);
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
