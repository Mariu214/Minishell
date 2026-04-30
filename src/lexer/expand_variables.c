/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:13 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 13:40:15 by malaimo          ###   ########.fr       */
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

char	*add_sub(t_data *data, char *sub, char *temp, char *temp2)
{
	char	*content;
	char	*content2;

	content = ft_strjoin_gc(sub, temp, &data->gc);
	if (temp2 && ft_strlen(temp2))
	{
		content2 = ft_strjoin_gc(content, temp2, &data->gc);
		ft_delone_gc(content, &data->gc);
		ft_delone_gc(temp2, &data->gc);
		return (ft_delone_gc(temp, &data->gc), content2);
	}
	else
		return (ft_delone_gc(temp, &data->gc), content);
}

char	*replace_value(t_data *data, char *str, int i, char *sub)
{
	char	*temp;
	char	*temp2;

	temp2 = NULL;
	temp = ft_calloc_gc(1, ft_strlen(ft_itoa(data->dollar)), &data->gc);
	if (!temp)
		return (NULL);
	temp = ft_itoa(data->dollar);
	if (str[i])
	{
		if (is_dollar(str + i))
			temp2 = expander(data, str + i, 0, NULL);
		else
			temp2 = ft_substr_gc(str, i, ft_strlen(str), &data->gc);
	}
	if (sub)
		return (add_sub(data, sub, temp, temp2));
	else
		return (add_end(data, temp, temp2));
}

char	*expander(t_data *data, char *str, int i, char *sub)
{
	char	*temp;
	char	*content;
	// char	*temp2;

	while (str[i] && str[i] != '$')
		i++;
	if (!str[i])
		return (0);
	if (i != 0)
		sub = ft_substr_gc(str, 0, i, &data->gc);
	if (!str[++i])
		return (NULL);
	if (str[i] == '?')
		return (replace_value(data, str, i + 1, sub));
	// temp2 = ft_substr_gc(str, i, find_dollar(str + i), )
	temp = ft_getenv_gc(str + i, data->env, &data->gc);
	if (!temp)
		return (NULL);
	if (!sub)
		return (temp);
	content = ft_strjoin_gc(sub, temp, &data->gc);
	if (!content)
		return (ft_delone_gc(temp, &data->gc), NULL);
	return (ft_delone_gc(temp, &data->gc), content);
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
			content = expander(data, temp->content, 0, NULL);
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
