/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/09 10:55:05 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    lexing_pipe(t_data *data, int i)
{
    int j;
    
    j = i;
    while (data->str[j] && data->str[j] == '|')
        j++;
}

int    new_lexer(t_data *data)
{
    int i;
    data->list = NULL;
    char    *temp;
    int j;

    i = 0;
    while (data->str[i])
    {
        temp = ft_substr_gc(data->str, i, 2, &data->gc);
        if (data->str[i] == '|')
        {
            while (data->str[j] && (data->str[j] != '<' || data->str[j] != '>' 
                    || data->str[j] != '|'))
                j++;
            ft_delone(temp, data->gc);
            ft_substr()
            ft_add_node(&data->list, temp, OU_TRUNC);
        }
        if (ft_strcmp(temp, ">>") == 0)
        {
            ft_add_node(&data->list, temp, HEREDOC);
        }
        temp = ft_substr_gc(data->str, i, 1, &data->gc);
        if (ft_strcmp(temp, ">") == 0)
        {
            ft_add_node(&data->list, temp, INPUT);
        }
        if (ft_strcmp(temp, "<") == 0)
        {
            ft_add_node(&data->list, temp, OU_APPEND);
        }
        i++;
    }
    return (0);
}

int test_lexer(t_data *data)
{
    int result;

    result = new_lexer(data);
    return (result);
}