/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/14 14:28:53 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int     last_pipe(t_data *data, t_lexst **list)
{
    pid_t child;
    int status;
    int return_value;

    return_value = 0;
    child = fork();
    if (!child)
    {
        // while ((*list))
        // {
            return_value = parsing_cmd(data, list);
        //     (*list) = (*list)->next;
        // }
        exit(return_value);
    }
    else
    {
        while ((*list) && (*list)->type != PIPE)
            (*list) = (*list)->next;
        waitpid(child, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
    }
    return (0);
}

int     apply_pipe(t_data *data, t_lexst **list)
{
    pid_t child;
    int end_pipe[2];
    int return_value;
    
    return_value = 0;
    pipe(end_pipe);
    child = fork();
    if (!child)
    {
        dup2(end_pipe[1], 1);
        close(end_pipe[0]);
        // while ((*list) && (*list)->type != PIPE)
        // {
            return_value = parsing_cmd(data, list);
            (*list) = (*list)->next;
        // }
        if ((*list)->type == PIPE)
            (*list) = (*list)->next;
        exit(return_value);
    }
    else
    {
        dup2(end_pipe[0], 0);
        close(end_pipe[1]);
        while ((*list) && (*list)->type != PIPE)
            (*list) = (*list)->next;
        if ((*list)->type == PIPE)
            (*list) = (*list)->next;
    }
    return (0);
}

int     find_pipe(t_data *data)
{
    pid_t child;
    t_lexst *temp;
    int     status;

    child = fork();
    if (!child)
    {
        while (data->list->previous)
            data->list = data->list->previous;
        temp = data->list;
        while (data->pipedone < data->pipenb)
        {
            apply_pipe(data, &temp);
            data->pipedone++;
        }
        exit(last_pipe(data, &temp));
    }
    else
    {
        waitpid(child, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
    }
    return (0);
}

static int     parsing_last_pipe(t_data *data)
{
    t_lexst *temp;
    
    temp = NULL;
    free(data->str);
    print_pipe(countpipe(data) - 1);
    data->str = ft_scan("pipe> ", 0);
    if (!data->str)
        return (ft_shellerror_gc("malloc error(parsing_last_pipe)\n", data, 0, 1));
    lexer(data, &temp);
    while (temp->previous)
        temp = temp->previous;
    while (data->list->next)
        data->list = data->list->next;
    temp->previous = data->list;
    data->list->next = temp;
    while (data->list->previous)
        data->list = data->list->previous;
    free(data->str);
    data->str = NULL;
    return (0);
}

int     parsing_pipe(t_data *data)
{
    t_lexst *temp;
    
    if (data->str[0] == '|')
        return (ft_shellerror_gc("Minishell: parse error near `|'\n", data, 1, 1));
    temp = data->list;
    while (temp->next)
    {
        temp = temp->next;
        if (is_there('|', temp->content))
        {
            if (ft_strlen(temp->content) > 1)
                return (ft_shellerror_gc("Minishell: parse error near `|'\n", data, 1, 1));
        }
    }
    if (is_there('|', temp->content))
        parsing_last_pipe(data);
    data->pipenb = countpipe(data);
    if (data->pipenb)
        data->pipedone = 0;
    else
        data->pipedone = 1;
    return (0);
}
