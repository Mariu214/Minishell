/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:24:50 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/21 15:59:30 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int parser(t_data *data, t_lexst **list)
{
    if ((*list)->type == WORD)
        return (0);
    else if ((*list)->type == CMD)
        return (parsing_cmd(data, list));
    else if ((*list)->type == INPUT)
        return (0);
    else if ((*list)->type == OU_APPEND)
        return (0);
    else if ((*list)->type == OU_TRUNC)
        return (0);
    else if ((*list)->type == HEREDOC)
        return (0);
    else if ((*list)->type == PIPE)
        return (0);
    else if ((*list)->type == BUILT_IN)
        return (0);
    return (0);
}

int init_parser(t_data *data)
{
    int     return_value = 0;
    // t_lexst *temp;

    if (parsing_quote(&data->list, data))
        return (1);
    if (parsing_pipe(data, data->list))
        return (1);
    // temp = data->list;
    // while (temp)
    // {
    //     return_value = parser(data, &temp);
    // }
    return_value = find_pipe(data);
    return (return_value);
}
