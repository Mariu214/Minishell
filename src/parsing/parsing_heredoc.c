/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:41:11 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/26 11:17:15 by malaimo          ###   ########.fr       */
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
    return;
}