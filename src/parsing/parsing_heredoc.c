/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:41:11 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/30 09:02:29 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data, char *lim)
{
    if (!data->str[1])
    {
        ft_error_gc("minishell: syntax error near unexpected token `newline'\n", &data->gc, 1);
    }
    here_doc(lim, data->pipenb, data);
    return ;
}