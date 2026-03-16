/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/16 10:57:56 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_pipe(int pipenb)
{
	int	i;

	i = 0;
	while (i < pipenb)
	{
		ft_printf_fd(2, "pipe ");
		i++;
	}
}

static void	here_doc_next(char *lim, int end_pipe[2], int pipenb)
{
	char	*gnl;
	char	*join;

	print_pipe(pipenb);
	ft_printf_fd(2, "heredoc> ");
	join = ft_strjoin(lim, "\n");
	gnl = gnl_lim(0, join);
	close(end_pipe[0]);
	while (ft_strcmp(gnl, join) != 0)
	{
		print_pipe(pipenb);
		ft_printf_fd(2, "heredoc> ");
		ft_printf_fd(end_pipe[1], "%s", gnl);
		free(gnl);
		gnl = gnl_lim(0, join);
	}
	free(join);
	free(gnl);
	// exit(0);
	return;
}

void	here_doc(char *lim, int pipenb)
{
	int		end_pipe[2];
	pid_t	parent;

	pipe(end_pipe);
	parent = fork();
	if (!parent)
		here_doc_next(lim, end_pipe, pipenb);
	else
	{
		wait(NULL);
		close(end_pipe[1]);
		dup2(end_pipe[0], 0);
	}
}
