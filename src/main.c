/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/13 16:46:30 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(void)
{
	char	*line;
	t_gc	*gc;
    char    *exit;
    char    **str;

    exit = "exit";
    gc = NULL;
    line = NULL;
    while (ft_strcmp(line, exit) != 0)
    {
        line = readline(">minishell ");
        if (!line)
            ft_error_gc("Error\nCouldn't read line\n", &gc);
        str = ft_split_gc(line, ' ', &gc);
        init_parsing(str, &gc);
    }
    ft_free_all_gc(&gc);
    return (0);
}

// test here_doc
// int     main(int argc, char *argv[], char *envp[])
// {
//     (void)argc;
//     here_doc(argv[1], 0);
//     exec(argv[2], envp);
// }
