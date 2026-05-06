/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:25:51 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 10:08:45 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	lexing_word(t_data *data, int *i, t_lexst **list)
{
	int j;
	char *temp;
	
	while (data->str[*i] && data->str[*i] == ' ')
		(*i)++;
	j = *i;
	while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
		&& data->str[j] != '|' && data->str[j] != ' ')
		j++;
	temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
	if (!temp)
		return (1);
	*i = j;
	ft_add_node(list, temp, define_type(WORD, WRD), &data->gc);
	return (0);
}