/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/14 10:39:38 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int	process_running = 0;

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	*line;
// 	t_data	data;

// 	(void)argc;
// 	(void)argv;
// 	if (!envp[0])
// 		return (1);
// 	data.gc = NULL;
// 	data.dollar = 0;
// 	data.env = ft_splitdup(envp);
// 	line = NULL;
// 	while (ft_strcmp(line, "exit") != 0)
// 	{
// 		init_signal(&data.sig_int, &data.sig_quit, &data.sig_child,
// 			&data.sig_child_slash);
// 		sigaction(SIGINT, &data.sig_int, NULL);
// 		sigaction(SIGQUIT, &data.sig_quit, NULL);
// 		line = readline(">minishell ");
// 		if (!line)
// 			ft_shellerror_gc("exit\n", &data, 0);
// 		if (line[0])
// 			add_history(line);
// 		process_running = 1;
// 		data.str = ft_split_gc(line, ' ', &data.gc);
// 		data.dollar = parsing(&data);
// 		process_running = 0;
// 		ft_free_all_gc(&data.gc);
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	if (!envp[0])
		return (1);
	data.gc = NULL;
	data.dollar = 0;
	data.env = ft_splitdup(envp);
	data.str = NULL;
	while (ft_strcmp(data.str, "exit") != 0)
	{
		init_signal(&data.sig_int, &data.sig_quit, &data.sig_child,
			&data.sig_child_slash);
		sigaction(SIGINT, &data.sig_int, NULL);
		sigaction(SIGQUIT, &data.sig_quit, NULL);
		data.str = readline(">minishell ");
		if (!data.str)
			ft_shellerror_gc("exit\n", &data, 0);
		if (data.str[0])
			add_history(data.str);
		process_running = 1;
		data.dollar = test_lexer(&data);
		parser(&data, &data.list);
		process_running = 0;
		ft_free_all_gc(&data.gc);
	}
	return (0);
}