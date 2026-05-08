/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/08 13:24:41 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	*g_datacpy = NULL;

int	main(int argc, char *argv[], char *envp[])
{
	static t_data	data;
	char			*line;

	init_data(&data, argc, argv, envp);
	line = ft_calloc(1, 1);
	while (ft_strcmp(line, "exit") != 0)
		init_loop(&data, &line);
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
