/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/15 15:48:02 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*line;
    t_data  data;

    (void)argc;
    (void)envp;
    (void)argv;
    data.gc = NULL;
    line = NULL;
    while (ft_strcmp(line, "exit") != 0)
    {
        line = readline(">minishell ");
        printf("%s\n", line);
        if (!line)
            ft_error_gc("Error\nCouldn't read line\n", &data.gc);
        data.str = ft_split_gc(line, ' ', &data.gc);
        init_parsing(&data, envp);
    }
    rl_clear_history();
    ft_free_all_gc(&data.gc);
    return (0);
}

// test here_doc
// int     main(int argc, char *argv[], char *envp[])
// {
//     (void)argc;
//     here_doc(argv[1], 0);
//     exec(argv[2], envp);
// }
