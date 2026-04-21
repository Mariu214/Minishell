/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/21 12:21:28 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int echo(char *str)
// {
//     int     i;
//     char    **temp;
    
//     i = 1;
//     temp = ft_split_sentence(str, ' ',   "\'\"");
//     if (temp[i])
//     {
//         if ((ft_strcmp(temp[i], "-n") == 0))
//         {
//             i++;
//             while (temp[i])
//             {
//                 ft_printf("%s", temp[i]);
//                 if (temp[i + 1])
//                     ft_printf(" ");
//                 i++;
//             }
//         }
//         else
//         {
//             while (temp[i])
//             {
//                 ft_printf("%s", temp[i]);
//                 if (temp[i + 1])
//                     ft_printf(" ");
//                 i++;
//             }
//             ft_printf("\n");
//         }
//     }
//     return (0);
// }

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
