/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/05 15:26:09 by jdelmott         ###   ########.fr       */
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

int	parsing_expand_quote(t_data *data, int *i, char **temp)
{
	char	*tmp;
	int		j;

	j = (*i) + 1;
	tmp = ft_strdup_gc(data->str, &data->gc);
	if (!tmp[j] || (tmp[j] && (tmp[j] == '<' || tmp[j] == '>' || tmp[j] == '|'
				|| tmp[j] == ' ' || tmp[j] == '\'' || tmp[j] == '"')))
		return ((*temp) = ft_renew_one_gc((*temp), data->str[*i], &data->gc),
			(*i) += 1, 1);
	else if (tmp[j] && tmp[j] == '?')
	{
		(*temp) = ft_renew_gc((*temp), ft_itoa(data->dollar), 0, &data->gc);
		(*i) += 2;
		return (1);
	}
	return (0);
}

int	expand_quote(t_data *data, int *i, char **temp)
{
	char	*env;
	char	*s;

	if (parsing_expand_quote(data, i, temp))
		return (0);
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

int	lexing_quote(t_data *data, int *i, t_type type, t_lexst **list)
{
	char	*temp;
	char	quote;
	int		j;

	j = (*i);
	quote = -1;
	temp = ft_strdup_gc("", &data->gc);
	while (data->str[j] && data->str[j] == ' ')
		j++;
	while (data->str[j])
	{
		if (data->str[j] && (data->str[j] == '\'' || data->str[j] == '"')
				&& quote == -1)
		{
			quote = data->str[j];
			j++;
		}
		while (quote != -1 && data->str[j] && data->str[j] != quote)
		{
			if (data->str[j] && data->str[j] == '$' && quote != '\''
				&& data->str[j + 1])
			{
				if (expand_quote(data, &j, &temp))
					return (ft_add_node(list, temp, define_type(type,
								CLOSED_D_QUOTE), &data->gc), 1);
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
		while (data->str[j] && data->str[j] != ' ' && data->str[j] != '|'
			&& data->str[j] != '<' && data->str[j] != '>'
			&& data->str[j] != '\'' && data->str[j] != '"')
		{
			if (data->str[j] && data->str[j] == '$' && quote != '\''
				&& data->str[j + 1] && data->str[j + 1] != '?')
			{
				if (expand_quote(data, &j, &temp))
					return (ft_add_node(list, temp, define_type(type,
								CLOSED_D_QUOTE), &data->gc), 1);
			}
			else
			{
				temp = ft_renew_one_gc(temp, data->str[j], &data->gc);
				j++;
			}
		}
		if (!data->str[j] || (data->str[j] != '\'' && data->str[j] != '"'))
			break ;
	}
	ft_add_node(list, temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
	*i = j;
	return (0);
}
