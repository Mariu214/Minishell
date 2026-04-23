/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/23 11:44:50 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int echo(t_lexst **list)
{
    int option;

    option = 0;
    *list = (*list)->next;
    if (!(*list) || (*list)->type != BUILT_IN)
        return (printf("\n"), 0);
    if (ft_strcmp((*list)->content, "-n") == 0)
    {
        option = 1;
        while (*list && (*list)->type == BUILT_IN 
                && ft_strcmp((*list)->content, "-n") == 0)
            *list=(*list)->next;
    }
    while (*list && (*list)->type == BUILT_IN)
    {
        printf("%s", (*list)->content);
        *list = (*list)->next;
        if (*list && (*list)->type == BUILT_IN)
            printf(" ");
    }
    if (option == 0)
        printf("\n");
    return (0);
}
