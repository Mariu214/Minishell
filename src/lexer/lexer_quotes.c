/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/29 11:11:54 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int choose_quote(t_data *data, t_lexst **list, int *i)
{
    int j;

    j = *i;
    while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
			&& data->str[j] != '|' && data->str[j] != ' ')
    {
        if (data->str[j] == '"')
            return (lexing_d_quote(data, i, WORD, list));
        if (data->str[j] == '\'')
            return (lexing_s_quote(data, i, WORD, list));
        
    }
}

int is_quote(char *src, int j, char q)
{
    while (src[j] && src[j] == ' ')
        j++;
    while (src[j] && src[j] != ' ')
    {
        if (src[j] == q)
            return (1);
        j++;
    }
    return (0);
}

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

    j = *i;
    num = 0;
    while (data->str[j])
    {
        if (data->str[j] && data->str[j] == '"')
            num++;
        if (num && num % 2 == 0 && data->str[j] && (data->str[j]  == ' ' || data->str[j] == '|' || data->str[j] == '<' || data->str[j] == '>'))
            break ;
        j++;
    }
    temp = rm_quote(ft_substr_gc(data->str, *i, j - *i, &data->gc), '"', data);
    if (num % 2 == 0 && num != 0)
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

int     lexing_s_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
    char    *temp;
    int     j;
    int     num;

    j = *i;
    num = 0;
    while (data->str[j])
    {
        if (data->str[j] && data->str[j] == '\'')
            num++;
        if (num && num % 2 == 0 && data->str[j] && (data->str[j]  == ' ' || data->str[j] == '|' || data->str[j] == '<' || data->str[j] == '>'))
            break ;
        j++;
    }
    temp = rm_quote(ft_substr_gc(data->str, *i, j - *i, &data->gc), '\'', data);
    if (num % 2 == 0 && num != 0)
    {
        ft_add_node(list, temp, define_type(type, CLOSED_S_QUOTE), &data->gc);
        *i = j + 1;
    }
    else
    {
        ft_add_node(list, temp, define_type(type, OPEN_S_QUOTE), &data->gc);
        *i = j;
    }
    return (0);
}
