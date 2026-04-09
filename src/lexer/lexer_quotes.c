/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/09 12:33:14 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int      lexing_d_quote(t_data *data, int *i)
{
    int j;
    char *temp;

    j = *i + 1;
    ft_add_node(&data->list, "\"", D_QUOTE);
    while (data->str[j] && data->str[j] != '"')
        j++;
    if (j > *i + 1)
    {
        temp = ft_substr_gc(data->str, *i + 1, j - (*i + 1), &data->gc);
        if (!temp)
            return (1);
        ft_add_node(&data->list, temp, WORD);
    }
    if (data->str[j] && data->str[j] == '"')
        ft_add_node(&data->list, "\"", D_QUOTE);
    *i = j + 1;
    return (0);
}

int      lexing_s_quote(t_data *data, int *i)
{
    int j;
    char *temp;

    j = *i + 1;
    ft_add_node(&data->list, "'", S_QUOTE);
    while (data->str[j] && data->str[j] != '\'')
        j++;
    if (j > *i + 1)
    {
        temp = ft_substr_gc(data->str, *i + 1, j - (*i + 1), &data->gc);
        if (!temp)
            return (1);
        ft_add_node(&data->list, temp, WORD);
    }
    if (data->str[j] && data->str[j] == '\'')
        ft_add_node(&data->list, "'", S_QUOTE);
    *i = j + 1;
    return (0);
}