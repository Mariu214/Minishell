/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/30 10:57:46 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <termios.h>

static char	*here_doc_next(char *lim, t_data *data)
{
	char			*scan;
	char			*doc;
	char			*nl;
	struct termios	termios;

	sigaction(SIGINT, &data->sig_child, NULL);
	sigaction(SIGQUIT, &data->sig_quit, NULL);
	tcgetattr(0, &termios);
	// termios.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &termios);
	scan = ft_calloc_gc(1, 1, &data->gc);
	doc = ft_calloc_gc(1, 1, &data->gc);
	nl = ft_strjoin_gc(lim, "\n", &data->gc);
	while (ft_strcmp(scan, nl) != 0)
	{
		ft_delone_gc(scan, &data->gc);
		print_pipe(data->pipenb);
		scan = ft_scan_gc("heredoc> ", 1, &data->gc, data->old_stdin);
		// printf("scan = %s taille = %ld\n", scan, ft_strlen(scan));
		if (!scan || ft_strlen(scan) == 0)
		{
			ft_printf_fd(2, "\n");
			ft_shellerror_gc("", data, 0, 0);
		}
		else if (ft_strcmp(scan, nl) != 0)
			doc = ft_renew_gc(doc, scan, 0, &data->gc);
	}
	// ft_printf_fd(end_pipe[1], "%s", doc);
	return (doc);
	// (void)data;
	// ft_printf_fd(2, "heredoc> ");
	// join = ft_strjoin_gc(lim, "\n", &data->gc);
	// gnl = ft_gnl_gc(0, &data->gc);
	// close(end_pipe[0]);
	// while (ft_strcmp(gnl, join) != 0 && gnl)
	// {
	// 	print_pipe(pipenb);
	// 	ft_printf_fd(2, "heredoc> ");
	// 	ft_printf_fd(end_pipe[1], "%s", gnl);
	// 	ft_delone_gc(gnl, &data->gc);
	// 	gnl = ft_gnl_gc(0, &data->gc);
	// }
	// if (!gnl)
	// {
	// 	ft_printf_fd(2, "\n");
	// 	ft_shellerror_gc("", data, 2, 0);
	// }
	// ft_shellerror_gc("", data, 0, 0);
}

int	here_doc(char *lim, t_data *data)
{
	pid_t	parent;
	int		signal;
	char	*doc;

	// int		end_pipe[2];
	pipe(data->pipe_heredoc);
	parent = fork();
	if (!parent)
	{
		doc = here_doc_next(lim, data);
		ft_printf_fd(data->pipe_heredoc[1], "%s", doc);
		ft_printf_fd(data->pipe_heredoc[1], "\0");
		close(data->pipe_heredoc[0]);
		close(data->pipe_heredoc[1]);
		data->pipe_heredoc[0] = -1;
		data->pipe_heredoc[1] = -1;
		ft_shellerror_gc("", data, 0, 0);
	}
	else
	{
		waitpid(parent, &signal, 0);
		close(data->pipe_heredoc[1]);
		dup2(data->pipe_heredoc[0], 0);
		close(data->pipe_heredoc[0]);
		data->pipe_heredoc[0] = -1;
		data->pipe_heredoc[1] = -1;
		if (WIFEXITED(signal))
			return (WEXITSTATUS(signal));
	}
	return (0);
}
