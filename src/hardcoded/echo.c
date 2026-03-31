/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/31 15:07:49 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int echo(char *str)
{
    int     i;
    char    **temp;
    
    i = 1;
    temp = ft_split_sentence(str, ' ',   "\'\"");
    if (temp[i])
    {
        if ((ft_strcmp(temp[i], "-n") == 0))
        {
            i++;
            while (temp[i])
            {
                ft_printf("%s", temp[i]);
                if (temp[i + 1])
                    ft_printf(" ");
                i++;
            }
        }
        else
        {
            while (temp[i])
            {
                ft_printf("%s", temp[i]);
                if (temp[i + 1])
                    ft_printf(" ");
                i++;
            }
            ft_printf("\n");
        }
    }
    return (0);
}