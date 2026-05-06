/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:42:46 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 15:43:25 by jdelmott         ###   ########.fr       */
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
			return (lqt(data, i, WORD, list));
		if (data->str[j] == '\'')
			return (lqt(data, i, WORD, list));
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
