/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/19 13:37:14 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int	process_running = 0;

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_data	data;

	(void)argc;
	(void)argv;
	data.gc = NULL;
    data.env = ft_splitcpy_gc(envp, &data.gc);
	line = NULL;
	while (ft_strcmp(line, "exit") != 0)
	{
		init_signal(&data.sig_int, &data.sig_quit, &data.sig_child,
			&data.sig_child_slash);
		sigaction(SIGINT, &data.sig_int, NULL);
		sigaction(SIGQUIT, &data.sig_quit, NULL);
		line = readline(">minishell ");
		if (!line)
			ft_error_gc("", &data.gc, 0);
		if (line[0])
			add_history(line);
		process_running = 1;
		data.str = ft_split_gc(line, ' ', &data.gc);
		parsing(&data);
		process_running = 0;
	}
	ft_free_all_gc(&data.gc);
	return (0);
}
