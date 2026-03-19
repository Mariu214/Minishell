/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:33:02 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 16:37:32 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t  ft_splitlen(char **str)
{
    size_t i;

    i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}