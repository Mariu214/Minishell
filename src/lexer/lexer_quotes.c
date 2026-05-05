/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/05 10:13:00 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	choose_quote(t_data *data, t_lexst **list, int *i)
{
	int	j;

    j = *i;
    while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
			&& data->str[j] != '|' && data->str[j] != ' ')
    {
        if (data->str[j] == '"')
            return (lexing_quote(data, i, WORD, list));
        if (data->str[j] == '\'')
            return (lexing_quote(data, i, WORD, list));
        j++;
    }
    return (0);
}

int	is_quote(char *src, int j, char q)
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

static char	*rm_quote(char *src, char quote, t_data *data)
{
	int		i;
	int		len;
	char	*retu;

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

int	lexing_d_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
	char	*temp;
	int		j;
	int		num;

    j = *i;
    num = 0;
    while (data->str[j])
    {
        if (data->str[j] && data->str[j] == '"')
            num++;
        if (num && num % 2 == 0 && data->str[j] && (data->str[j]  == ' ' || data->str[j] == '|' 
            || data->str[j] == '<' || data->str[j] == '>' || data->str[j] == '\''))
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

int	lexing_s_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
	char	*temp;
	int		j;
	int		num;

    j = *i;
    num = 0;
    while (data->str[j])
    {
        if (data->str[j] && data->str[j] == '\'')
            num++;
        if (num && num % 2 == 0 && data->str[j] && (data->str[j]  == ' ' || data->str[j] == '|' 
            || data->str[j] == '<' || data->str[j] == '>' || data->str[j] == '"'))
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

int     expand_quote(t_data *data, int *i, char **temp)
{
    char    *env;
    char    *s;

    s = ft_strdup_gc("", &data->gc);
    (*i)++;
    while (data->str[*i] && data->str[*i] != '"' && data->str[*i] != ' ')
    {
        s = ft_renew_one_gc(s, data->str[*i], &data->gc);
        (*i)++;
    }
    env = ft_getenv_gc(s, data->env, &data->gc);
    if (!env)
        return (1);
    (*temp) = ft_renew_gc((*temp), env, 0, &data->gc);
    return (0);
}

int     lexing_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
    char    *temp;
    char    quote;
    int     j;

    j = (*i);
    quote = -1;
    temp = ft_strdup_gc("", &data->gc);
    while (data->str[j] && data->str[j] == ' ')
        j++;
    while (data->str[j])
    {
        if (data->str[j] && (data->str[j] == '\'' || data->str[j] == '"') && quote == -1)
        {
            quote = data->str[j];
            j++;
        }
        while (quote != -1 && data->str[j] && data->str[j] != quote)
        {
            if (data->str[j] && data->str[j] == '$' && quote != '\'' && data->str[j + 1] && data->str[j + 1] != '?')
            {
                if (expand_quote(data, &j, &temp))
                    return (ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc), 1);
            }
            else
            {
                temp = ft_renew_one_gc(temp, data->str[j], &data->gc);
                j++;
            }
        }
        if (quote == data->str[j])
        {
            j++;
            quote = -1;
        }
        while (data->str[j] && data->str[j]  != ' ' && data->str[j] != '|' 
            && data->str[j] != '<' && data->str[j] != '>' && data->str[j] != '\'' && data->str[j] != '"')
        {
            if (data->str[j] && data->str[j] == '$' && quote != '\''&& data->str[j + 1] && data->str[j + 1] != '?')
            {
                if (expand_quote(data, &j, &temp))
                    return (ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc), 1);
            }
            else
            {
                temp = ft_renew_one_gc(temp, data->str[j], &data->gc);
                j++;
            }
        }
        if (!data->str[j] || (data->str[j] != '\'' && data->str[j] != '"'))
            break;
    }
    ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
    *i = j;
    return (0);
}
