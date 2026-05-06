/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:30:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/05 14:15:46 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    ft_exit(t_data *data, t_lexst **list)
{
    int i;

    i = 0;
    *list=(*list)->next;
    if (!list || (*list)->type != BUILT_IN)
        ft_shellerror_gc("exit\n", data, 0, 0);
    if ((*list)->next && (*list)->next->type == BUILT_IN)
        ft_shellerror_gc("exit\ntoo many arguments\n", data, 1, 0);
    while ((*list)->content[i])
    {
        if (!((*list)->content[i] >= '0' && (*list)->content[i] <= '9')
            && ((*list)->content[i] != '-') && (*list)->content[i] != '+')
            ft_shellerror_gc("exit\nnumeric argument required\n", data, 2, 0);
        i++;
    }
    ft_shellerror_gc("exit\n", data, ft_atoi((*list)->content) % 256, 0);
}