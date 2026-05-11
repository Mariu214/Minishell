/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:24:50 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/11 19:52:18 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	init_parser(t_data *data)
{
	int	return_value;

	return_value = 0;
	g_datacpy->process = 1;
	if (parsing_pipe(data, data->list))
		return (2);
	return_value = find_pipe(data);
	if (dup2(data->old_stdin, STDIN_FILENO) < 0)
		ft_shellerror_gc("error: dup2\n", data, 0, 0);
	if (dup2(data->old_stdout, STDOUT_FILENO) < 0)
		ft_shellerror_gc("error: dup2\n", data, 0, 0);
	g_datacpy->process = 0;
	return (return_value);
}
