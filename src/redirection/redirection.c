/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:32:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/08 15:14:08 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	schr_redirection(t_data *data, int i)
{
	int		j;

	j = i;
	while (data->line[j].str && !data->line[j].is_pipe)
	{
		if (data->line[j].is_redirection)
			do_redirection(data, j);
		j++;
	}
}

void	do_redirection(t_data *data, int i)
{
	if (data->line[i].is_redirection)
	{

		if (ft_strnstr(data->line[i].str, ">>", 2))
			output_redirection_append(ft_split_gc(data->line[i].str, ' ', &data->gc)[1]);
		else if (ft_strnstr(data->line[i].str, "<<", 2))
			parsing_heredoc(data, ft_split_gc(data->line[i].str, ' ',
					&data->gc)[1]);		
		else if (ft_strnstr(data->line[i].str, "<", 1))
			input_redirection(ft_split_gc(data->line[i].str, ' ', &data->gc)[1]);
		else if (ft_strnstr(data->line[i].str, ">", 1))
			output_redirection_trunc(ft_split_gc(data->line[i].str, ' ', &data->gc)[1]);
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
