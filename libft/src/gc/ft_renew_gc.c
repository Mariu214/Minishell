/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:16:57 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 13:54:21 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_renew_gc(char *start, char *end, t_gc **gc)
{
	char *temp;

    if (!start || !end || !gc)
        return (NULL);
    temp = ft_strjoin_gc(start, end, gc);
    ft_delone_gc(start, gc);
	return (temp);
}