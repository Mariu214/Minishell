/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/20 16:25:11 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char    *rm_quote(char *src, char quote, t_data *data)
{
    int i;
    int len;
    char    *retu;

    len = 0;
    i = 0;
    while (src[i])
    {
        if (src[i] != quote)
            len++;
        i++;
    }
    i = 0;
    retu = ft_calloc_gc(sizeof(char), len + 1, &data->gc);
    if (!retu)
        return (NULL);
    len = 0;
    while (src[i])
    {
        if (src[i] != quote)
        {
            retu[len] = src[i];
            len++;
        }
        i++;
    }
    return (retu);
}

int     lexing_d_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
    char    *temp;
    int     j;
    int     num;

    j = *i + 1;
    num = 0;
    while (data->str[j])
    {
        if (data->str[j] && data->str[j] == '"')
            num++;
        if (num / 2 == 0)
        {
            while (data->str[j] && data->str[j] != ' ' && data->str[j] != '"')
                j++;
        }
        if (num / 2 == 0 && data->str[j] && data->str[j] == ' ')
            break ;
        j++;
    }
    temp = rm_quote(ft_substr_gc(data->str, *i, j - *i, &data->gc), '"', data);
    if (num / 2 == 0)
    {
        ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
        *i = j + 1;
    }
    else
    {
        ft_add_node(list, temp, define_type(type, OPEN_D_QUOTE), &data->gc);
        *i = j;
    }
    return (0);
}

// int      lexing_d_quote(t_data *data, int *i, t_type type, t_lexst **list)
// {
//     int j;
//     char *temp;

//     j = *i + 1;
//     while (data->str[j] && data->str[j] != '"')
//         j++;
//     if (j > *i + 1)
//     {
//         temp = ft_substr_gc(data->str, *i + 1, j - (*i + 1), &data->gc);
//         if (!temp)
//             return (1);
//         if (data->str[j] && data->str[j] == '"')
//         {
//             ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
//             *i = j + 1;
//         }
//         else
//         {
//             ft_add_node(list, temp, define_type(type, OPEN_D_QUOTE), &data->gc);
//             *i = j;
//         }
//     }
//     return (0);
// }

int      lexing_s_quote(t_data *data, int *i, t_type type, t_lexst **list)
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
            ft_add_node(list, temp, define_type(type, CLOSED_S_QUOTE), &data->gc);
            *i = j + 1;
        }
        else
        {
            ft_add_node(list, temp, define_type(type, OPEN_S_QUOTE), &data->gc);
            *i = j;
        }
    }
    return (0);
}
