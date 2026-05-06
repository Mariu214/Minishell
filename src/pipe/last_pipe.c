/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:41:06 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:40:08 by jdelmott         ###   ########.fr       */
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
