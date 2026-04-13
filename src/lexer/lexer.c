/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/13 15:02:29 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		lexing_word(t_data *data, int *i)
{
	int     j;
    char    *temp;
    
    j = *i;
	while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
			&& data->str[j] != '|' && data->str[j] != ' ')
        j++;
    temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    *i = j;
    ft_add_node(&data->list, temp, define_type(WORD, WRD), &data->gc);
    return (0);
}

int		lexing_redirection(t_data *data, int *i)
{
    int     j;
    char    *temp;
    
    j = *i;
    while (data->str[j] && (data->str[j] == '<' || data->str[j] == '>'))
        j++;
    temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    if (lexing_precise_redirection(data, temp))
        return (1);
    if (data->str[j] && data->str[j] == ' ')
		j++;
    *i = j;
    j = 0;
    while (data->str[*i] && data->str[*i] != '>' && data->str[*i] != '<'
			&& data->str[*i] != '|')
	{
        if (lexing_sort(data, i, j))
            return (1);
        j++;
	}
    return (0);
}

int		lexing_pipe(t_data *data, int *i)
{
    int     j;
    char    *temp;
    
    j = *i;
    while (data->str[j] && data->str[j] == '|')
        j++;
    temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    *i = j;
    ft_add_node(&data->list, temp, define_type(PIPE, WRD), &data->gc);
    return (0);
}

int    lexer(t_data *data)
{
    int i;
    data->list = NULL;

    i = 0;
    while (data->str[i])
    {
        if (data->str[i] == '|')
        {
            if (lexing_pipe(data, &i))
                return (1);
        }
        else if (data->str[i] == '<' || data->str[i] == '>')
        {
            if (lexing_redirection(data, &i))
                return (1);
        }
		else if (data->str[i] == '"')
        {
            if (lexing_d_quote(data, &i, CMD))
                return (1);
        }
        else if (data->str[i] == '\'')
        {
            if (lexing_s_quote(data, &i, CMD))
                return (1);
        }
        else if (data->str[i] == ' ')
            i++;
		else if (data->str[i])
		{
			if (lexing_cmd(data, &i))
				return (1);
		}
    }
    while (data->list->previous)
        data->list = data->list->previous;
    lexing_built_in(data);
    return (0);
}

int test_lexer(t_data *data)
{
    int result;

    result = lexer(data);
    // ft_print_list(data->list);
    return (result);
}
