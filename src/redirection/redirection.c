/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:32:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/16 14:34:40 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	schr_redirection(t_lexst **list)
{
	t_lexst	*temp;

	temp = (*list);
	while (temp && temp->type != PIPE)
	{
		if (temp->type >= INPUT && temp->type <= HEREDOC)
		{
			if (do_redirection(temp->type, temp->next) != 0)
				return (1);
		}
		temp = temp->next;
	}
	return (0);			
}

int	do_redirection(t_type redir, t_lexst *file)
{
	if (file->type != WORD)
		return (0);
	else if (redir == HEREDOC)
		return (0);
	else if (redir == OU_APPEND)
		return (output_redirection_append(file->content));
	else if (redir == OU_TRUNC)
		return (output_redirection_trunc(file->content));
	else if (redir == INPUT)
		return (input_redirection(file->content));
	return (0);
}

int	input_redirection(char *file)
{
	int	fd;

	fd = open_file(file, 0);
	if (fd < 0)
		return (1);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (1);
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	output_redirection_trunc(char *file)
{
	int	fd;

	fd = open_file(file, 2);
	if (fd < 0)
		return (1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (1);
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	output_redirection_append(char *file)
{
	int	fd;

	fd = open_file(file, 1);
	if (fd < 0)
		return (1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (1);
	if (close(fd) < 0)
		return (1);
	return (0);
}
