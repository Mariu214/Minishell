/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:08:18 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 12:28:41 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_renew_gc(char *start, char *end, t_gc **gc)
{
	char	*temp;

	if (!start || !end || !gc)
		return (NULL);
	temp = ft_strjoin_gc(start, end, gc);
	ft_delone_gc(start, gc);
	return (temp);
}
