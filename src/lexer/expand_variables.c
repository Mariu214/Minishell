/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:13 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/29 14:54:53 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int is_dollar(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '$' && str[i + 1])
            return (1);
        i++;
    }
    return (0);
}

char    *expander(t_data *data, char *str, int i, char *sub)
{
    char    *temp;
    char    *content;
    char    *temp2;

    while (str[i] && str[i] != '$')
            i++;
    if (!str[i])
        return (0);
    if (i != 0)
        sub = ft_substr_gc(str, 0, i, &data->gc);
    if (!str[++i])
        return (NULL);
    if (str[i] == '?')
    {
        i++;
        temp = ft_calloc_gc(1, 1, &data->gc);
        temp = ft_itoa(data->dollar);
        if (str[i])
            temp2 = ft_substr_gc(str, i, ft_strlen(str), &data->gc);
    }
    else 
        temp = ft_getenv_gc(str + i, data->env, &data->gc);
    if (!temp)
        return (NULL);
    if (!sub)
        return (temp);
    content = ft_strjoin_gc(sub, temp, &data->gc);
    if (temp2)
        content = ft_strjoin_gc(content, temp, &data->gc);
    if (!content)
        return (ft_delone_gc(temp, &data->gc), NULL);
    return (ft_delone_gc(temp, &data->gc), content);
}

int check_expand(t_data *data, t_lexst **list)
{
    t_lexst *temp;
    char    *content;

    temp = *list;
    while (temp)
    {
        if (is_expand(temp->content))
        {
            content = expander_bis(data, temp->content, 0, NULL);
            if (!content)
                ft_delone(data, &temp);
        }
        else if (is_dollar(temp->content))
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
