/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:24:50 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/23 12:06:24 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int init_parser(t_data *data)
{
    int     return_value = 0;
    // t_lexst *temp;

    process_running = 1;
    if (parsing_pipe(data, data->list))
        return (1);
    // temp = data->list;
    // while (temp)
    // {
    //     return_value = parser(data, &temp);
    // }
    return_value = find_pipe(data);
    process_running = 0;
    return (return_value);
}
