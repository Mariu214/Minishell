/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/27 09:52:12 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int    lexer(t_data *data, t_lexst **list, int *i)
{
    if (data->str[*i] == '|')
        return (lexing_pipe(data, i, list));
    else if (data->str[*i] == '<' || data->str[*i] == '>')
    {
        if (lexing_redirection(data, i, list))
            return (1);
        if (data->str[*i] && lexing_word(data, i, list))
            return (1);
    }
	else if (is_quote(data->str, *i, '"'))
        return (lexing_d_quote(data, i, CMD, list));
    else if (is_quote(data->str, *i, '\''))
        return (lexing_s_quote(data, i, CMD, list));
    else if (data->str[*i] == ' ')
        i++;
	else if (data->str[*i])
		return (lexing_cmd(data, i, list));
    return (0);
}

int init_lexer(t_data *data, t_lexst **list)
{
    int i;
    int return_value;

    i = 0;
    return_value = 0;
    while (data->str[i])
    {
        return_value = lexer(data, list, &i);
        if (return_value)
            return (return_value);
    }
    while ((*list)->previous)
        *list = (*list)->previous;
    lexing_built_in(list);
    check_expand(data, list);
    return (0);
}

int test_lexer(t_data *data)// rajoute un node vide apres les redirextions
{
    int result;

    data->list = NULL;
    
    result = init_lexer(data, &data->list);
    // ft_print_list(data->list);
    return (result);
}
