/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:09:29 by jdelmott          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/09 17:29:19 by jdelmott         ###   ########.fr       */
=======
/*   Updated: 2026/04/10 11:58:47 by malaimo          ###   ########.fr       */
>>>>>>> prototype
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void print_type(t_token type)
{
    if (type == CMD)
        ft_printf_fd(2, "CMD\n");
    else if (type == WORD)
        ft_printf_fd(2, "WORD\n");
    else if (type == D_QUOTE)
        ft_printf_fd(2, "D_QUOTE\n");
    else if (type == S_QUOTE)
        ft_printf_fd(2, "S_QUOTE\n");
<<<<<<< HEAD
    else if (type == OU_TRUNC)
        ft_printf_fd(2, "OU_TRUNC\n");
=======
>>>>>>> prototype
    else if (type == INPUT)
        ft_printf_fd(2, "INPUT\n");
    else if (type == OU_APPEND)
        ft_printf_fd(2, "OU_APPEND\n");
    else if (type == HEREDOC)
        ft_printf_fd(2, "HEREDOC\n");
    else if (type == PIPE)
        ft_printf_fd(2, "PIPE\n");
    else if (type == OU_TRUNC)
        ft_printf_fd(2, "OU_TRUNC\n");
    else
        ft_printf_fd(2, "ERROR = %i, %i\n", type, OU_APPEND);
}

void    ft_print_list(t_lexst *lexer)
{
    t_lexst *temp;

    temp = lexer;
    while (temp)
    {
        ft_printf_fd(2, "%s, ", temp->content);
        print_type(temp->type);
        temp = temp->previous;
    }
}
