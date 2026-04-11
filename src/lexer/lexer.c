/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:57:35 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/09 16:26:30 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
    ft_add_node(&data->list, temp, WORD, &data->gc);
    return (0);
}

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
    ft_add_node(&data->list, temp, CMD, &data->gc);
	if (data->str[j] && data->str[j] == ' ')
		j++;
	*i = j;
	while (data->str[*i] && (data->str[*i] != '>' || data->str[*i] != '<'
			|| data->str[*i] != '|'))
	{
		if (lexing_word(data, i))
			return (1);
        if (data->str[*i] && data->str[*i] == ' ')
		    *i += 1;
	}
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
            if (ft_add_node(&data->list, ft_substr_gc(data->str, i, 2, &data->gc), HEREDOC, &data->gc))
                return (1);
            i += 2;
        }
        else if ((str[i] && str[i + 1] && str[i] == '>' && str[i + 1] == '>'))
        {
            if (ft_add_node(&data->list, ft_substr_gc(data->str, i, 2, &data->gc), OU_APPEND, &data->gc))
                return (1);
            i += 2;
        }
        else if (str[i] && str[i] == '<')
        {
            if (ft_add_node(&data->list, ft_substr_gc(data->str, i, 1, &data->gc), INPUT, &data->gc))
                return (1);
            i++;
        }
        else if (str[i] && str[i] == '>')
        {
            if (ft_add_node(&data->list, ft_substr_gc(data->str, i, 1, &data->gc), OU_TRUNC, &data->gc))
                return (1);
            i++;
        }
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
    if (lexing_precise_redirection(data, temp))
        return (1);
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
    ft_add_node(&data->list, temp, PIPE, &data->gc);
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
    ft_print_list(data->list);
    return (result);
}