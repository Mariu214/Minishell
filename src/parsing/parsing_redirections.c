/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:41:01 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/14 11:09:48 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//pourquoi pas mettre la valeur derreur dans la structure ?

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
        printf("minishell: syntax error near unexpected token `%s\n'", list->content);
        return (2);
    }
    return (0);
}

int parsing_heredoc(t_lexst *list)
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
        printf("minishell: syntax error near unexpected token `%s\n'", list->content[0]);
        return (2);
    }
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
        printf("minishell: syntax error near unexpected token `%s\n'", list->content[0]);
        return (2);
    }
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
        printf("minishell: syntax error near unexpected token `%s\n'", list->content[0]);
        return (2);
    }
}