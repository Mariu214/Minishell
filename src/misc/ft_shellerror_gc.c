/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellerror_gc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:18:04 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 13:14:34 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_shellerror_gc(char *str, t_data *data, long out, int mode)
{
	ft_printf_fd(2, "%s", str);
	ft_free_all_gc(&data->gc);
	if (mode == 0)
	{	
		close_fds(data);
		close(1);
		close(0);
		close(2);
		free_tab(data->env);
		exit(out);
	}
	else
		return (out);
}

int	close_fds(t_data *data)
{
	if (data->pipe_heredoc[0] != -1)
	{
		close(data->pipe_heredoc[0]);
		data->pipe_heredoc[0] = -1;
	}
	if (data->pipe_heredoc[1] != -1)
	{
		close(data->pipe_heredoc[1]);
		data->pipe_heredoc[1] = -1;
	}
	if (data->old_stdin != -1)
	{
		close(data->old_stdin);
		data->old_stdin = -1;
	}
	if (data->old_stdout != -1)
	{
		close(data->old_stdout);
		data->old_stdout = -1;
	}
	return (1);
}
