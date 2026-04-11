/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/11 12:55:33 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int      lexing_d_quote(t_data *data, int *i, t_type type)
{
    int j;
    char *temp;

    j = *i + 1;
    while (data->str[j] && data->str[j] != '"')
        j++;
    if (j > *i + 1)
    {
        temp = ft_substr_gc(data->str, *i + 1, j - (*i + 1), &data->gc);
        if (!temp)
            return (1);
        if (data->str[j] && data->str[j] == '"')
        {
            ft_add_node(&data->list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
            *i = j + 1;
        }
        else
        {
            ft_add_node(&data->list, temp, define_type(type, OPEN_D_QUOTE), &data->gc);
            *i = j;
        }
    }
    return (0);
}

int      lexing_s_quote(t_data *data, int *i, t_type type)
{
    int j;
    char *temp;

    j = *i + 1;
    while (data->str[j] && data->str[j] != '\'')
        j++;
    if (j > *i + 1)
    {
        temp = ft_substr_gc(data->str, *i + 1, j - (*i + 1), &data->gc);
        if (!temp)
            return (1);
        if (data->str[j] && data->str[j] == '\'')
        {
            ft_add_node(&data->list, temp, define_type(type, CLOSED_S_QUOTE), &data->gc);
            *i = j + 1;
        }
        else
        {
            ft_add_node(&data->list, temp, define_type(type, OPEN_S_QUOTE), &data->gc);
            *i = j;
        }
    }
    return (0);
}
