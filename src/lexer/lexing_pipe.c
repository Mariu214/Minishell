/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:25:14 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 10:58:41 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	lexing_pipe(t_data *data, int *i, t_lexst **list)
{
	int		j;
	char	*temp;

	j = *i;
	while (data->str[j] && data->str[j] == '|')
		j++;
	temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
	if (!temp)
		return (1);
	*i = j;
	ft_add_node(list, temp, define_type(PIPE, WRD), &data->gc);
	return (0);
}
