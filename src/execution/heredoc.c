/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/23 11:30:46 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*here_doc_next(char *lim, t_data *data)
{
	char	*scan;
	char	*doc;
	char	*nl;

	print_pipe(data->pipenb);
	scan = ft_calloc_gc(1, 1, &data->gc);
	doc = ft_calloc_gc(1, 1, &data->gc);
	nl = ft_strjoin_gc(lim, "\n", &data->gc);
	while (ft_strcmp(scan, nl) != 0)
	{
		ft_delone_gc(scan, &data->gc);
		scan = ft_scan_gc("heredoc> ", 1, &data->gc);
		if (ft_strcmp(scan, nl) != 0)
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
	int		end_pipe[2];
	// pid_t	parent;
	// int		signal;
	char	*doc;

	pipe(end_pipe);
	// sigaction(SIGINT, &data->sig_child, NULL);
	// sigaction(SIGQUIT, &data->sig_quit, NULL);
	doc = here_doc_next(lim, data);
	// parent = fork();
	// if (!parent)
	// {
		ft_printf_fd(end_pipe[1], "%s", doc);
		ft_printf_fd(end_pipe[1], "\0");
		// exit (0);
	// }
	// else
	// {
    //     waitpid(parent, &signal, 0);
		// data->str = ft_renew_gc(data->str, doc, 2, &data->gc);
		close(end_pipe[1]);
		dup2(end_pipe[0], 0);
		close(end_pipe[0]);
		// if (WIFEXITED(signal))
		// 	return (WEXITSTATUS(signal));
	// }
	return (0);
}
