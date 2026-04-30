/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:41:06 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/30 10:59:27 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_last_pipe(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i && (line[i] == ' ' || line[i] == '|'))
	{
		if (line[i] == '|')
			return (1);
		i--;
	}
	return (0);
}

// char    *add_last_pipe(char *line, t_data *data)
// {
//     char    *added;
//     char    *scan;

//     if (is_last_pipe(line))
//     {
//         print_pipe(countpipe())
//     }
// }
