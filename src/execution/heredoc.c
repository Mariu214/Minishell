/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 14:00:07 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_pipe(int pipenb)
{
	int	i;

	i = 0;
	while (i < pipenb)
	{
		ft_printf_fd(2, "pipe ");
		i++;
	}
}

static void	here_doc_next(char *lim, int end_pipe[2], int pipenb, t_data *data)
{
	char	*gnl;
	char	*join;

	print_pipe(pipenb);
	(void)data;
	ft_printf_fd(2, "heredoc> ");
	join = ft_strjoin_gc(lim, "\n", &data->gc);
	gnl = ft_gnl_gc(0, &data->gc);
	close(end_pipe[0]);
	while (ft_strcmp(gnl, join) != 0)
	{
		print_pipe(pipenb);
		ft_printf_fd(2, "heredoc> ");
		ft_printf_fd(end_pipe[1], "%s", gnl);
		ft_delone_gc(gnl, &data->gc);
		gnl = ft_gnl_gc(0, &data->gc);
	}
	ft_error_gc("", &data->gc, 0);
}

void	here_doc(char *lim, int pipenb, t_data *data)
{
	int		end_pipe[2];
	pid_t	parent;

	pipe(end_pipe);
	sigaction(SIGINT, &data->sig_child, NULL);
	sigaction(SIGQUIT, &data->sig_quit, NULL);
	parent = fork();
	if (!parent)
		here_doc_next(lim, end_pipe, pipenb, data);
	else
	{
		int signal;

        waitpid(parent, &signal, 0);
		close(end_pipe[1]);
		dup2(end_pipe[0], 0);
	}
}
