/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:32:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 09:20:09 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	do_redirection(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (data->line[i].is_redirection)
		{
			if (ft_strcmp(data->line[i].str, "<") == 0)
				input_redirection(data->line[i + 1].str);
			else if (ft_strcmp(data->line[i].str, ">") == 0)
				output_redirection_trunc(data->line[i + 1].str);
			else if (ft_strcmp(data->line[i].str, ">>") == 0)
				output_redirection_append(data->line[i + 1].str);
		}
		i++;
	}
}

void	input_redirection(char *file)
{
	int	fd;

	fd = open_file(file, 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	output_redirection_trunc(char *file)
{
	int	fd;

	fd = open_file(file, 2);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	output_redirection_append(char *file)
{
	int	fd;

	fd = open_file(file, 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
