/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:13 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/05 10:13:04 by malaimo          ###   ########.fr       */
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

    temp = *list;
    while (temp)
    {
        if (is_dollar(temp->content) && temp->word_type != CLOSED_D_QUOTE)
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
