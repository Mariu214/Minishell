/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/17 14:16:01 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int signal_received = 0;

int main(int argc, char *argv[], char *envp[])
{
	char	*line;
    t_data  data;

    (void)argc;
    (void)argv;
    data.gc = NULL;
    line = NULL;
    while (ft_strcmp(line, "exit") != 0)
    {
        init_signal(&data.sig_int, &data.sig_quit);
        sigaction(SIGINT, &data.sig_int, NULL);
        sigaction(SIGQUIT, &data.sig_quit, NULL);
        line = readline(">minishell ");
        if (!line)
            ft_free_all_gc(&data.gc);
        if (signal_received)
            signal_received = 0;
        else
        {
            data.str = ft_split_gc(line, ' ', &data.gc);
            init_parsing(&data, envp);
        }
    }
    ft_free_all_gc(&data.gc);
    return (0);
}

