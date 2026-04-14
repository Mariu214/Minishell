/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:41:11 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/14 11:39:30 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data, char *lim)
{
    if (!data->str[1])
    {
        ft_shellerror_gc("minishell: syntax error near unexpected token `newline'\n", data, 1, 0);
    }
    here_doc(lim, data->pipenb, data);
    return ;
}