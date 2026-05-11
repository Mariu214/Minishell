/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:22:25 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 17:05:29 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static int	lqt_next(t_data *data, t_type type, t_lexst **list, t_lqt *l)
{
	if (data->str[l->j] && (data->str[l->j] == '\'' || data->str[l->j] == '"')
		&& l->quote == -1)
	{
		l->quote = data->str[l->j];
		l->j++;
	}
	while (l->quote != -1 && data->str[l->j] && data->str[l->j] != l->quote)
	{
		if (data->str[l->j] && data->str[l->j] == '$' && l->quote != '\''
			&& data->str[l->j + 1])
		{
			if (expand_quote(data, &l->j, &l->temp))
				return (ft_add_node(list, l->temp, define_type(type,
							CLOSED_D_QUOTE), &data->gc), 1);
		}
		else
		{
			l->temp = ft_renew_one_gc(l->temp, data->str[l->j], &data->gc);
			l->j++;
		}
	}
	return (0);
}

static int	lqt_next_next(t_data *data, t_type type, t_lexst **list, t_lqt *l)
{
	while (data->str[l->j] && data->str[l->j] != ' ' && data->str[l->j] != '|'
		&& data->str[l->j] != '<' && data->str[l->j] != '>'
		&& data->str[l->j] != '\'' && data->str[l->j] != '"')
	{
		if (data->str[l->j] && data->str[l->j] == '$' && l->quote != '\''
			&& data->str[l->j + 1])
		{
			if (expand_quote(data, &l->j, &l->temp))
				return (ft_add_node(list, l->temp, define_type(type,
							CLOSED_D_QUOTE), &data->gc), 1);
		}
		else
		{
			l->temp = ft_renew_one_gc(l->temp, data->str[l->j], &data->gc);
			l->j++;
		}
	}
	return (0);
}

int	lqt(t_data *data, int *i, t_type type, t_lexst **list)
{
	t_lqt	l;

	l.j = (*i);
	l.quote = -1;
	l.temp = ft_strdup_gc("", &data->gc);
	while (data->str[l.j] && data->str[l.j] == ' ')
		l.j++;
	while (data->str[l.j])
	{
		if (lqt_next(data, type, list, &l) == 1)
			return (1);
		if (l.quote == data->str[l.j])
		{
			l.j++;
			l.quote = -1;
		}
		if (lqt_next_next(data, type, list, &l) == 1)
			return (1);
		if (!data->str[l.j] || (data->str[l.j] != '\''
				&& data->str[l.j] != '"'))
			break ;
	}
	ft_add_node(list, l.temp, define_type(type, CLOSED_D_QUOTE), &data->gc);
	*i = l.j;
	return (0);
}
