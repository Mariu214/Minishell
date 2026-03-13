/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/13 14:28:35 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int main(void)
{
	char	*line;
	t_gc	*gc;
	char	**args;
	int		i;

    gc = NULL;
    i = 0;
    line = readline(">minishell ");
    if (!line)
        ft_error_gc("Error\nCouldn't read line\n", &gc);
    printf("%s\n", line);
    args = ft_split_gc(line, ' ', &gc);
    if (!args)
        ft_free_all_gc(&gc);
    while (args[i])
        printf("%s\n", args[i++]);
    rl_clear_history();
    ft_free_all_gc(&gc);
    return (0);
}*/

// test here_doc
int     main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    here_doc(argv[1], 0);
    exec(argv[2], envp);
}
