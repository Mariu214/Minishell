/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/29 11:44:34 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data *g_datacpy = NULL;

int	main(int argc, char *argv[], char *envp[])
{
	static t_data	data;
	char	*line;

	(void)argc;
	(void)argv;
	g_datacpy = &data;
	if (!envp[0])
		return (1);
	data.gc = NULL;
	data.dollar = 0;
	g_datacpy->process = 0;
	data.env = ft_splitdup(envp);
	line = ft_calloc(1, 1);
	data.old_stdin = dup(STDIN_FILENO);
    data.old_stdout = dup(STDOUT_FILENO);
	data.pipe_heredoc[0] = -1;
	data.pipe_heredoc[1] = -1;
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
		if (data.str[0])
		{
			test_lexer(&data);
			if (data.list)
				data.dollar = init_parser(&data);
		}
		if (data.str && data.str[0])
			add_history(data.str);
		ft_free_all_gc(&data.gc);
	}
	close(data.old_stdin);
	close(data.old_stdout);
	g_datacpy = NULL;
	free(line);
	close(1);
	close(0);
	close(2);
	free_tab(data.env);
	return (0);
}
