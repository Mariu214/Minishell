/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:27:44 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 09:22:44 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int parser_export(t_lexst **list)
// {
//     int i;
    
//     *list = (*list)->next;
//     if (*list && (*list)->type == BUILT_IN)
//     {
//         i = 0;
//         if ((*list)->content[0] == '-')
//             return (printf("minishell: export: `%s': no options are supported", (*list)->content), 1);
//         if ((!ft_isdigit((*list)->content[0]) && (*list)->content[0] != '_')
//             || ft_strchr((*list)->content, '-'))
//             return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
//         while ((*list)->content[i])
//         {
//             if (!ft_isalnum((*list)->content[i]) && (*list)->content[i] != '_')
//                 return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
//             i++;
//         }
//         *list = (*list)->next;
//     }
//     while (*list && (*list)->type == BUILT_IN)
//     {
//         i = 0;
//         if ((!ft_isdigit((*list)->content[0]) && (*list)->content[0] != '_')
//             || ft_strchr((*list)->content, '-'))
//             return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
//         while ((*list)->content[i])
//         {
//             if (!ft_isalnum((*list)->content[i]) && (*list)->content[i] != '_')
//                 return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
//             i++;
//         }
//         *list = (*list)->next;
//     }
//     return (0);
// }

int parser_export(t_lexst **list)
{
    int i;
    
    *list = (*list)->next;
    if (*list && (*list)->type == BUILT_IN)
    {
        i = 0;
        if ((*list)->content[0] == '-')
            return (printf("minishell: export: `%s': no options are supported", (*list)->content), 1);
        if ((!ft_isdigit((*list)->content[0]) && (*list)->content[0] != '_')
            || ft_strchr((*list)->content, '-'))
            return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
        while ((*list)->content[i])
        {
            if (!ft_isalnum((*list)->content[i]) && (*list)->content[i] != '_')
                return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
            i++;
        }
        *list = (*list)->next;
    }
    while (*list && (*list)->type == BUILT_IN)
    {
        i = 0;
        if ((!ft_isdigit((*list)->content[0]) && (*list)->content[0] != '_')
            || ft_strchr((*list)->content, '-'))
            return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
        while ((*list)->content[i])
        {
            if (!ft_isalnum((*list)->content[i]) && (*list)->content[i] != '_')
                return (printf("minishell: export: `%s': not a valid identifier", (*list)->content), 1);
            i++;
        }
        *list = (*list)->next;
    }
    return (0);
}

void    parser_built_in(t_lexst **list)
{
    if (ft_strcmp((*list)->content , "export") == 0)
        parser_export(list);
    if (ft_strcmp((*list)->content , "unset") == 0)
        parser_export(list);
}