/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/09 13:42:25 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		lexing_cmd(t_data *data, int *i)
{
	int     j;
    char    *temp;
    
    j = *i;
	while (data->str[j] && (data->str[j] != '>' || data->str[j] != '<'
			|| data->str[j] != '|'))
        j++;
	temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    ft_add_node(&data->list, temp, CMD);
	if (data->str[j] && data->str[j] == ' ')
		j++;
	*i = j;
	while (data->str[*i] && (data->str[*i] != '>' || data->str[*i] != '<'
			|| data->str[*i] != '|'))
	{
		if (lexing_word(data, i))
			return (1);
        if (data->str[*i] && data->str[*i] == ' ')
		    *i++;
	}
    return (0);
}

int		lexing_word(t_data *data, int *i)
{
	int     j;
    char    *temp;
    
    j = *i;
	while (data->str[j] && (data->str[j] != '>' || data->str[j] != '<'
			|| data->str[j] != '|' || data->str[j] != ' '))
        j++;
    temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    *i = j;
    ft_add_node(&data->list, temp, WORD);
    return (0);
}

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
    else if (jsp == 1)
    {
        if (lexing_cmd(data, i))
            return (1);
    }
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
    ft_add_node(&data->list, temp, REDIRECTION);
    if (data->str[j] && data->str[j] == ' ')
		j++;
    *i = j;
    j = 0;
    while (data->str[*i] && (data->str[*i] != '>' || data->str[*i] != '<'
			|| data->str[*i] != '|'))
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
    ft_add_node(&data->list, temp, PIPE);
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
            if (lexing_redirections(data, &i))
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
		else if (data->str[i])
		{
			if (lexing_cmd(data, &i))
				return (1);
		}
    }
    return (0);
}

int test_lexer(t_data *data)
{
    int result;

    result = lexer(data);
    return (result);
}