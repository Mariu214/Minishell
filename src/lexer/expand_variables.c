/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:13 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 14:53:47 by malaimo          ###   ########.fr       */
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
		return(NULL);
	content = ft_itoa(data->dollar);
	if (!content)
		return(NULL);
	return (content);
}

char	*expander(t_data *data, char *str, int i)
{
	char	*temp;
	char	*content;
	int		limit;

	content = NULL;
	while(str[i])
	{
		while (str[i] && str[i] != '$')
			i++;
		if (!str[i])
			return (0);
		if (i != 0)
			content = ft_substr_gc(str, 0, i, &data->gc);
		if (!str[++i])
			return (ft_renew_one_gc(content, '$', &data->gc)); 
		if (str[i] == '?')
		{
			content = ft_renew_gc(content, rtv(data), 2, &data->gc);
			i++;
		}
		else if (str[i])
		{
			limit = find_dollar(str + i);
			temp = ft_substr_gc(str, i, limit, &data->gc);
			i = limit;
			content = ft_renew_gc(content, ft_getenv_gc(temp, data->env, &data->gc), 2, &data->gc);
			ft_delone_gc(temp, &data->gc);
		}
		else
			return (content);
	}
	return (content);
}

int	check_expand(t_data *data, t_lexst **list)
{
	t_lexst	*temp;
	char	*content;

	temp = *list;
	while (temp)
	{
		if (is_dollar(temp->content))
		{
			content = expander(data, temp->content, 0);
			if (!content)
				ft_delone(data, &temp);
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
