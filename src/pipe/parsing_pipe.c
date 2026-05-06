/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 11:49:38 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	last_pipe(t_data *data, t_lexst **list)
{
	return (parsing_cmd(data, list));
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
		dup2(end_pipe[1], 1);
		close(end_pipe[0]);
		close(end_pipe[1]);
		return_value = schr_redirection(list, data);
		if (return_value != 0)
			ft_shellerror_gc("", data, return_value, 0);
		while ((*list) && (((*list)->type >= INPUT && (*list)->type <= HEREDOC)
				|| (*list)->type == WORD))
			(*list) = (*list)->next;
		return_value = parsing_cmd(data, list);
		(*list) = (*list)->next;
		if ((*list)->type == PIPE)
			(*list) = (*list)->next;
		ft_shellerror_gc("", data, return_value, 0);
	}
	else
	{
		wait(NULL);
		dup2(end_pipe[0], 0);
		close(end_pipe[1]);
		close(end_pipe[0]);
		while ((*list) && (*list)->type != PIPE)
			(*list) = (*list)->next;
		if ((*list)->type == PIPE)
			(*list) = (*list)->next;
	}
	return (0);
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
		return_value = last_pipe(data, &temp);
	return (return_value);
}

static int	parsing_last_pipe(t_data *data)
{
	t_lexst	*temp;
	char	*tmp;

	temp = NULL;
	tmp = ft_strdup_gc(data->str, &data->gc);
	tmp = ft_renew_gc(tmp, " ", 0, &data->gc);
	ft_delone_gc(data->str, &data->gc);
	data->str = ft_strdup_gc(NULL, &data->gc);
	while (!data->str[0])
	{
		ft_delone_gc(data->str, &data->gc);
		print_pipe(countpipe(data) - 1);
		data->str = ft_scan_gc("pipe> ", 0, &data->gc, 0);
	}
	if (!data->str)
		return (ft_shellerror_gc("malloc error(parsing_last_pipe)\n", data, 0,
				1));
	init_lexer(data, &temp);
	while (data->list->next)
		data->list = data->list->next;
	temp->previous = data->list;
	data->list->next = temp;
	while (data->list->previous)
		data->list = data->list->previous;
	if (parsing_pipe(data, temp))
		return (data->str = ft_renew_gc(tmp, data->str, 2, &data->gc), 1);
	if (parsing_quote(&data->list, data))
		return (data->str = ft_renew_gc(tmp, data->str, 2, &data->gc), 1);
	data->str = ft_renew_gc(tmp, data->str, 2, &data->gc);
	return (0);
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
			if (ft_strlen(temp->content) > 1)
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
