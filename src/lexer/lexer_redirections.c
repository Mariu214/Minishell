/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:24:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/11 12:05:15 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int     lexing_sort(t_data *data, int *i, int jsp)
{
    if (data->str[*i] == '"')
    {
        if (lexing_d_quote(data, i, WORD))
            return (1);
    }
    else if (data->str[*i] == '\'')
    {
        if (lexing_s_quote(data, i, WORD))
            return (1);
    }
    else if (jsp == 0)
    {
        if (lexing_word(data, i))
            return (1);
    }
    else if (jsp >= 1)
    {
        if (lexing_cmd(data, i))
            return (1);
    }
    return (0);
}

int     lexing_precise_redirection(t_data *data, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] && str[i + 1] && str[i] == '<' && str[i + 1] == '<')
        {
            if (ft_add_node(&data->list, ft_substr_gc(str, i, 2, &data->gc), define_type(HEREDOC, WRD), &data->gc))
                return (1);
            i += 2;
        }
        else if ((str[i] && str[i + 1] && str[i] == '>' && str[i + 1] == '>'))
        {
            if (ft_add_node(&data->list, ft_substr_gc(str, i, 2, &data->gc), define_type(OU_APPEND, WRD), &data->gc))
                return (1);
            i += 2;
        }
        else if (str[i] && str[i] == '<')
        {
            if (ft_add_node(&data->list, ft_substr_gc(str, i, 1, &data->gc), define_type(INPUT, WRD), &data->gc))
                return (1);
            i++;
        }
        else if (str[i] && str[i] == '>')
        {
            if (ft_add_node(&data->list, ft_substr_gc(str, i, 1, &data->gc), define_type(OU_TRUNC, WRD), &data->gc))
                return (1);
            i++;
        }
    }
    return (0);
}

