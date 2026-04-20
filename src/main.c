/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/20 09:35:14 by jdelmott         ###   ########.fr       */
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
	char	*line;

	(void)argc;
	(void)argv;
	if (!envp[0])
		return (1);
	data.gc = NULL;
	data.dollar = 0;
	data.env = ft_splitdup(envp);
	line = ft_calloc(1, 1);
	while (ft_strcmp(line, "exit") != 0)
	{		
		free(line);
		line = NULL;
		data.str = NULL;
		init_signal(&data.sig_int, &data.sig_quit, &data.sig_child,
			&data.sig_child_slash);
		sigaction(SIGINT, &data.sig_int, NULL);
		sigaction(SIGQUIT, &data.sig_quit, NULL);
		line = readline(">minishell ");		
		if (!line)
			ft_shellerror_gc("exit\n", &data, 0, 0);
		data.str = ft_strdup_gc(line, &data.gc);
		process_running = 1;
		if (data.str[0])
		{
			data.dollar = test_lexer(&data);
			init_parser(&data);
		}		
		if (data.str[0])
			add_history(data.str);
		process_running = 0;
		ft_free_all_gc(&data.gc);
	}
	return (0);
}