/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/17 14:11:36 by malaimo          ###   ########.fr       */
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

static void	here_doc_next(char *lim, int end_pipe[2], int pipenb, t_data *data)
{
	char	*gnl;
	char	*join;

	print_pipe(pipenb);
	(void)data;
    sigaction(SIGINT, &data->sig_int, NULL);
	ft_printf_fd(2, "heredoc> ");
	join = ft_strjoin(lim, "\n");
	if (!signal_received)
	{
		gnl = gnl_lim(0, join);
		close(end_pipe[0]);
		while (ft_strcmp(gnl, join) != 0 && !signal_received)
		{
			print_pipe(pipenb);
			ft_printf_fd(2, "heredoc> ");
			ft_printf_fd(end_pipe[1], "%s", gnl);
			free(gnl);
			gnl = gnl_lim(0, join);
		}
		free(gnl);
	}
	free(join);
	exit(0);
}

void	here_doc(char *lim, int pipenb, t_data *data)
{
	int		end_pipe[2];
	pid_t	parent;

	pipe(end_pipe);
	parent = fork();
	if (!parent)
		here_doc_next(lim, end_pipe, pipenb, data);
	else
	{
		int signal;

        waitpid(parent, &signal, 0);
		// printf("\na");
		close(end_pipe[1]);
		dup2(end_pipe[0], 0);
	}
}
