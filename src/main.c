/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/18 11:38:07 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int process_running = 0;

int main(int argc, char *argv[], char *envp[])
{
	char	*line;
    t_data  data;

    (void)argc;
    (void)argv;
    data.gc = NULL;
    line = NULL;
    printf("%d\n", getpid());
    while (ft_strcmp(line, "exit") != 0)
    {
        init_signal(&data.sig_int, &data.sig_quit, &data.sig_child, &data.sig_child_slash);
        sigaction(SIGINT, &data.sig_int, NULL);
        sigaction(SIGQUIT, &data.sig_quit, NULL);
        line = readline(">minishell ");
        if (!line)
            ft_error_gc("", &data.gc);
        process_running = 1;
        data.str = ft_split_gc(line, ' ', &data.gc);
        init_parsing(&data, envp);
        process_running = 0;
    }
    ft_free_all_gc(&data.gc);
    return (0);
}

