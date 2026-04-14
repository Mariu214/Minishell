/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipenb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:04:04 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/14 13:29:25 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int countpipe(t_data *data)
{
    t_lexst *temp;
    int     pipe_nb;

    temp = data->list;
    pipe_nb = 0;
    while (temp)
    {
        if (temp->type == PIPE)
            pipe_nb++;
        temp = temp->next;
    }
    return (pipe_nb);
}

void print_pipe(int pipenb)
{
    int i;
    
    i = 0;
    while (i < pipenb)
    {
        ft_printf_fd(2, "pipe ");
        i++;
    }
}
