/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/11 20:03:04 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	in_pipe(int *return_value, t_data *data, t_lexst **list)
{
	*return_value = schr_redirection(list, data);
	if (*return_value != 0)
		ft_shellerror_gc("", data, *return_value, 0);
	while ((*list) && (((*list)->type >= INPUT && (*list)->type <= HEREDOC)
			|| (*list)->type == WORD))
		(*list) = (*list)->next;
	*return_value = parsing_cmd(data, list);
	(*list) = (*list)->next;
	if ((*list)->type == PIPE)
		(*list) = (*list)->next;
	ft_shellerror_gc("", data, *return_value, 0);
}

int	apply_pipe(t_data *data, t_lexst **list)
{
	pid_t	child;
	int		end_pipe[2];
	int		return_value;

	return_value = 0;
	pipe(end_pipe);
	child = fork();
	if (!child)
	{
		if (dup2(end_pipe[1], 1) < 0)
			ft_shellerror_gc("error: dup2\n", data, 0, 0);
		close(end_pipe[0]);
		close(end_pipe[1]);
		in_pipe(&return_value, data, list);
	}
	else
	{
		if (dup2(end_pipe[0], 0) < 0)
			ft_shellerror_gc("error: malloc\n", data, 0, 0);
		while ((*list) && (*list)->type != PIPE)
			(*list) = (*list)->next;
		if ((*list)->type == PIPE)
			(*list) = (*list)->next;
	}
	return (close(end_pipe[1]), close(end_pipe[0]), 0);
}

int	find_pipe(t_data *data)
{
	t_lexst	*temp;
	int		return_value;

	while (data->list->previous)
		data->list = data->list->previous;
	temp = data->list;
	while (data->pipedone < data->pipenb)
	{
		return_value = apply_pipe(data, &temp);
		if (return_value != 0)
			return (return_value);
		data->pipedone++;
	}
	return_value = schr_redirection(&temp, data);
	if (return_value != 0)
		return (return_value);
	while (temp && ((temp->type >= INPUT && temp->type <= HEREDOC)
			|| temp->type == WORD))
		temp = temp->next;
	if (temp)
		return_value = parsing_cmd(data, &temp);
	return (return_value);
}

int	parsing_pipe(t_data *data, t_lexst *list)
{
	t_lexst	*temp;

	if (data->str[0] && data->str[0] == '|')
		return (ft_printf_fd(2, "Minishell: parse error near `|'\n"), 2);
	temp = list;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->type == PIPE)
		{
			if ((ft_strlen(temp->content) > 1) || (temp->previous
					&& temp->previous->type >= INPUT
					&& temp->previous->type <= HEREDOC))
				return (ft_printf_fd(2, "Minishell: parse error near `|'\n"),
					2);
		}
	}
	if (temp->type == PIPE)
		parsing_last_pipe(data);
	data->pipenb = countpipe(data);
	if (data->pipenb)
		data->pipedone = 0;
	else
		data->pipedone = 1;
	return (0);
}
