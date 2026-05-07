/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/07 16:29:24 by jdelmott         ###   ########.fr       */
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

	sigaction(SIGINT, &data->sig_chd, NULL);
	sigaction(SIGQUIT, &data->sig_qt, NULL);
	tcgetattr(0, &termios);
	termios.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &termios);
	scan = ft_calloc_gc(1, 1, &data->gc);
	doc = ft_calloc_gc(1, 1, &data->gc);
	nl = ft_strjoin_gc(lim, "\n", &data->gc);
	while (ft_strcmp(scan, nl) != 0)
	{
		ft_delone_gc(scan, &data->gc);
		print_pipe(data->pipenb);
		scan = ft_scan_gc("heredoc> ", 1, &data->gc, data->old_stdin);
		if (!scan || ft_strlen(scan) == 0)
			ft_shellerror_gc("\n", data, 0, 0);
		else if (ft_strcmp(scan, nl) != 0)
			doc = ft_renew_gc(doc, scan, 0, &data->gc);
	}
	return (doc);
}

int	here_doc(char *lim, t_data *data)
{
	pid_t	parent;
	int		signal;
	char	*doc;

	pipe(data->pipe_heredoc);
	parent = fork();
	if (!parent)
	{
		doc = here_doc_next(lim, data);
		ft_printf_fd(data->pipe_heredoc[1], "%s", doc);
		ft_printf_fd(data->pipe_heredoc[1], "\0");
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
