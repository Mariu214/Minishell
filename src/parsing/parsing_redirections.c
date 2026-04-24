/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:41:01 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/24 09:48:24 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int parsing_input(t_lexst *list)
{
    if (!list->next)
    {
        printf("minishell: syntax error near unexpected token `newline'\n");
        return (2);
    }
    list = list->next;
    if (list->type == OU_APPEND || list->type == PIPE || list->type == INPUT
        || list->type == OU_TRUNC)
    {
        printf("minishell: syntax error near unexpected token `%c'\n", list->content[0]);
        return (2);
    }
    return (input_redirection(list->content));
}

int parsing_heredoc(t_data *data, t_lexst *list)
{
    if (!list->next)
    {
        printf("minishell: syntax error near unexpected token `newline'\n");
        return (2);
    }
    list = list->next;
    if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
        || list->type == HEREDOC)
    {
        printf("minishell: syntax error near unexpected token `%c'\n", list->content[0]);
        return (2);
    }
    return (here_doc(list->content, data));
}

int parsing_ou_trunc(t_lexst *list)
{
    if (!list->next)
    {
        printf("minishell: syntax error near unexpected token `newline'\n");
        return (2);
    }
    list = list->next;
    if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
        || list->type == HEREDOC)
    {
        printf("minishell: syntax error near unexpected token `%c'\n", list->content[0]);
        return (2);
    }
    return (output_redirection_trunc(list->content));
}

int parsing_ou_append(t_lexst *list)
{
    if (!list->next)
    {
        printf("minishell: syntax error near unexpected token `newline'\n");
        return (2);
    }
    list = list->next;
    if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
        || list->type == HEREDOC)
    {
        printf("minishell: syntax error near unexpected token `%c'\n", list->content[0]);
        return (2);
    }
    return (output_redirection_append(list->content));
}