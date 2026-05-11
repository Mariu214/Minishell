/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/11 19:05:46 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <termios.h>

static void	expand_heredoc(char **str, t_data *data)
{
	int	i;
	char	*temp;
	char	*v;
	char	*getv;

	i = 0;
	temp = ft_strdup_gc("", &data->gc);
	getv = ft_strdup_gc("", &data->gc);
	v = ft_strdup_gc("", &data->gc);
	if (data->list->next && data->list->next->word_type != WRD)
		return ;
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			i++;
			if ((*str)[i] == '?')
			{
				temp = ft_renew_gc(temp, ft_itoa_gc(data->dollar, &data->gc), 0, &data->gc);
				i++;
			}
			else
			{
				while ((*str[i] && (*str)[i] != ' ' && (*str)[i] != '?' && (*str)[i] != '$'))
				{
					v = ft_renew_one_gc(v, (*str)[i], &data->gc);
					i++;
					ft_printf_fd(2, "%c\n", (*str)[i]);
				}
				getv = ft_getenv_gc(v, data->env, &data->gc);
				if (!getv)
				{
					ft_delone_gc((*str), &data->gc);
					(*str) = ft_strdup_gc(temp, &data->gc);
					return ;
				}
				temp = ft_renew_gc(temp, getv, 0, &data->gc);
			}
		}
		temp = ft_renew_one_gc(temp, (*str)[i], &data->gc);
		i++;
	}
	ft_delone_gc((*str), &data->gc);
	(*str) = ft_strdup_gc(temp, &data->gc);
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
	doc = ft_calloc_gc(1, 1, &data->gc);
	nl = ft_strjoin_gc(lim, "\n", &data->gc);
	while (ft_strcmp(scan, nl) != 0)
	{
		ft_delone_gc(scan, &data->gc);
		print_pipe(data->pipenb);
		scan = ft_scan_gc("heredoc> ", 1, &data->gc, data->old_stdin);
		if (!scan || ft_strlen(scan) == 0)
			ft_shellerror_gc("\n", data, 0, 0);
		expand_heredoc(&scan, data);
		if (ft_strcmp(scan, nl) != 0)
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
