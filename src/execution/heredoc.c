/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/11 20:03:58 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <termios.h>

static void	expand_heredoc(char **str, t_data *data)
{
	char	**temp;

	temp = ft_split_gc((*str), '\n', &data->gc);
	if (!temp)
		ft_shellerror_gc("error: malloc", data, 1, 0);
	if (data->list->next && data->list->next->word_type != WRD)
		return ;
	temp[0] = expander(data, temp[0], 0, 0);
	if (!temp[0])
		ft_shellerror_gc("error: malloc", data, 1, 0);
	ft_delone_gc((*str), &data->gc);
	(*str) = ft_strjoin_gc(temp[0], "\n", &data->gc);
	if (!(*str))
		ft_shellerror_gc("error: malloc", data, 1, 0);
}

static void	here_doc_next_next(t_data *data, char *nl, char **scan, char **doc)
{
	while (ft_strcmp((*scan), nl) != 0)
	{
		ft_delone_gc((*scan), &data->gc);
		print_pipe(data->pipenb);
		(*scan) = ft_scan_gc("heredoc> ", 1, &data->gc, data->old_stdin);
		if (!(*scan) || ft_strlen((*scan)) == 0)
			ft_shellerror_gc("\n", data, 0, 0);
		expand_heredoc(scan, data);
		if (!(*scan))
			ft_shellerror_gc("error: malloc\n", data, 0, 0);
		if (ft_strcmp((*scan), nl) != 0)
		{
			(*doc) = ft_renew_gc((*doc), (*scan), 0, &data->gc);
			if (!(*doc))
				ft_shellerror_gc("error: malloc\n", data, 0, 0);
		}
	}
}

static char	*here_doc_next(char *lim, t_data *data)
{
	char			*scan;
	char			*doc;
	char			*nl;
	struct termios	termios;

	sigaction(SIGINT, &data->sig_chd, NULL);
	sigaction(SIGQUIT, &data->sig_qt, NULL);
	ft_memset(&termios, 0, sizeof(termios));
	tcgetattr(0, &termios);
	termios.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &termios);
	scan = ft_calloc_gc(1, 1, &data->gc);
	if (!scan)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	doc = ft_calloc_gc(1, 1, &data->gc);
	if (!doc)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	nl = ft_strjoin_gc(lim, "\n", &data->gc);
	if (!nl)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	here_doc_next_next(data, nl, &scan, &doc);
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
