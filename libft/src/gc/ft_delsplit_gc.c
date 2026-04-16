/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delsplit_gc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:46:32 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/16 09:50:29 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int ft_delsplit_gc(char **tab, t_gc **gc)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (ft_delone_gc(tab[i], gc))
            return (1);
        i++;
    }
    if (ft_delone_gc(tab, gc))
        return (1);
    return (0);
}