/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:27:44 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/13 15:46:11 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int parser_export(t_lexst **list)
{
    while ((*list)->next && (*list)->next->type == BUILT_IN)
    {
        if (ft_strchr((*list)->content, '-'))
            return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
        *list = (*list)->next;
    }
    return (0);
}

void    parser_built_in(t_lexst **list)
{
    if (ft_strcmp((*list)->content , "export") == 0)
        parser_export(list);
}