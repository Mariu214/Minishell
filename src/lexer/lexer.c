/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/27 09:25:42 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int    lexer(t_data *data, t_lexst **list)
{
    int i;

    i = 0;
    while (data->str[i])
    {
        if (data->str[i] == '|')
        {
            if (lexing_pipe(data, &i, list))
                return (1);
        }
        else if (data->str[i] == '<' || data->str[i] == '>')
        {
            if (lexing_redirection(data, &i, list))
                return (1);
            if (data->str[i] && lexing_word(data, &i, list))
                return (1);
        }
		else if (is_quote(data->str, i, '"'))
        {
            if (lexing_d_quote(data, &i, CMD, list))
                return (1);
        }
        else if (is_quote(data->str, i, '\''))
        {
            if (lexing_s_quote(data, &i, CMD, list))
                return (1);
        }
        else if (data->str[i] == ' ')
            i++;
		else if (data->str[i])
		{
			if (lexing_cmd(data, &i, list))
				return (1);
		}
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
    
    result = lexer(data, &data->list);
    // ft_print_list(data->list);
    return (result);
}
