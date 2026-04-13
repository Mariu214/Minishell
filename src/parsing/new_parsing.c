/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:24:50 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/13 11:34:45 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int parser(t_lexst *list)
{
    if (list->type == WORD)
        return (0);
    else if (list->type == CMD)
        return (parsing_cmd(data));
    else if (list->type == D_QUOTE)
        return (0);
    else if (list->type == S_QUOTE)
        return (0);
    else if (list->type == INPUT)
        return (0);
    else if (list->type == OU_APPEND)
        return (0);
    else if (list->type == OU_TRUNC)
        return (0);
    else if (list->type == HEREDOC)
        return (0);
    else if (list->type == PIPE)
        return (0);
    return (0);
}

int init_parser(t_lexst *list)
{
    int     return_value;

    while (list->previous)
        list = list->previous;
    while (list->content)
    {
        return_value = parser(list);
        list = list->next;
    }
}