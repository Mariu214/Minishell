/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:13 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 14:56:30 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*add_end(t_data *data, char *temp, char *temp2)
{
	char	*content;

	if (!temp2)
		return (temp);
	content = ft_strjoin_gc(temp, temp2, &data->gc);
	if (!content)
	{
		ft_delone_gc(temp2, &data->gc);
		return (ft_delone_gc(temp, &data->gc), NULL);
	}
	ft_delone_gc(temp2, &data->gc);
	return (ft_delone_gc(temp, &data->gc), content);
}

char	*rtv(t_data *data)
{
	char	*content;
	int		size;

	size = ft_strlen(ft_itoa(data->dollar));
	content = ft_calloc_gc(1, size, &data->gc);
	if (!content)
		return (NULL);
	content = ft_itoa(data->dollar);
	if (!content)
		return (NULL);
	return (content);
}

int	with_dollar(t_data *data, char *str, int *i, char **content)
{
	char	*temp;
	int		limit;

	if (str[*i] == '?')
	{
		*content = ft_renew_gc(*content, rtv(data), 2, &data->gc);
		if (!*content)
			return (1);
		(*i)++;
	}
	else if (str[*i])
	{
		limit = find_dollar(str + (*i));
		temp = ft_substr_gc(str, *i, limit, &data->gc);
		if (!temp)
			return (1);
		*i += limit;
		*content = ft_renew_gc(*content, ft_getenv_gc(temp, data->env,
					&data->gc), 2, &data->gc);
		if (!*content)
			return (ft_delone_gc(temp, &data->gc), 1);
	}
	return (0);
}

char	*expander(t_data *data, char *str, int i, int j)
{
	char	*content;

	content = NULL;
	while (str[i])
	{
		while (str[i] && str[i] != '$')
			i++;
		if (i != j)
		{
			content = ft_renew_gc(content, ft_substr_gc(str, j, i - j,
						&data->gc), 2, &data->gc);
			if (!content)
				return (NULL);
		}
		if (!str[i])
			return (content);
		i++;
		if (!str[i])
			return (ft_renew_one_gc(content, '$', &data->gc));
		if (with_dollar(data, str, &i, &content))
			return (NULL);
		j = i;
	}
	return (content);
}

char	*check_expand(t_data *data, t_lexst **list)
{
	t_lexst	*temp;
	char	*content;

	temp = *list;
	while (temp)
	{
		if (is_dollar(temp->content) && temp->word_type != CLOSED_D_QUOTE)
		{
			content = expander(data, temp->content, 0, 0);
			if (!content)
			{
				ft_delone(data, &temp);
				*list = temp;
			}
			else
			{
				ft_delone_gc(temp->content, &data->gc);
				temp->content = content;
			}
		}
		if (temp)
			temp = temp->next;
	}
	return (0);
}
