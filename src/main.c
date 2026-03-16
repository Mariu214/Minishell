/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/16 12:09:10 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*line;
    t_data  data;
    // struct sigaction	signal;

    (void)argc;
    (void)argv;
    data.gc = NULL;
    line = NULL;
    // signal.sa_sigaction = signal_handler;
	// sigemptyset(&signal.sa_mask);
	// signal.sa_flags = SA_RESTART;
    while (ft_strcmp(line, "exit") != 0)
    {
        line = readline(">minishell ");
        if (!line)
            ft_free_all_gc(&data.gc);
        if (line )
        data.str = ft_split_gc(line, ' ', &data.gc);
        init_parsing(&data, envp);
    }
    ft_free_all_gc(&data.gc);
    return (0);
}

