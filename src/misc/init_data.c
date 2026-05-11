/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:33:43 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/11 19:49:32 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_loop(t_data *data, char **line)
{
	free(*line);
	*line = NULL;
	data->str = NULL;
	*line = readline(">minishell ");
	if (!*line)
		ft_shellerror_gc("exit\n", data, 0, 0);
	data->str = ft_strdup_gc(*line, &data->gc);
	if (!data->str)
		ft_shellerror_gc("error: malloc", data, 1, 0);
	if (data->str[0])
	{
		test_lexer(data);
		if (data->list)
			data->dollar = init_parser(data);
	}
	if (data->str && data->str[0])
		add_history(data->str);
	ft_free_all_gc(&data->gc);
}

void	init_data(t_data *data, int argc, char *argv[], char *envp[])
{
	if (!envp[0])
		exit(1);
	(void)argc;
	(void)argv;
	insig(&data->sig_it, &data->sig_qt);
	inseg(&data->sig_chd, &data->sig_sh);
	sigaction(SIGINT, &data->sig_it, NULL);
	sigaction(SIGQUIT, &data->sig_qt, NULL);
	g_datacpy = data;
	data->gc = NULL;
	data->dollar = 0;
	g_datacpy->process = 0;
	data->env = ft_splitdup(envp);
	data->old_stdin = dup(STDIN_FILENO);
	data->old_stdout = dup(STDOUT_FILENO);
	if (data->old_stdin < 0 || data->old_stdout < 0)
		ft_shellerror_gc("error: dup\n", data, 1, 0);
	data->pipe_heredoc[0] = -1;
	data->pipe_heredoc[1] = -1;
}
