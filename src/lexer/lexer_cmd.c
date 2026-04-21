/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:44:56 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/21 14:40:03 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		lexing_cmd(t_data *data, int *i, t_lexst **list)
{
	int     j;
    char    *temp;
    
    j = *i;
	while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
			&& data->str[j] != '|' && data->str[j] != '\'' && data->str[j] != '"' && data->str[j] != ' ')// pas encor sur et certain du ' '
        j++;
	temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    ft_add_node(list, temp, define_type(CMD, WRD), &data->gc);
	if (data->str[j] && data->str[j] == ' ')
		j++;
	*i = j;
    return (0);
}