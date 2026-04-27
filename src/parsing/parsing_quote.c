/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:23:26 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/27 09:49:16 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int last_quote(t_data *data, char *prompt, char q)
{
    char    *tmp;
    char    *scan;

    scan = ft_strdup_gc("", &data->gc);
    tmp = ft_strdup_gc(data->str, &data->gc);
    tmp = ft_renew_gc(tmp, " ", 0, &data->gc);
    ft_delone_gc(data->str, &data->gc);
    data->str = ft_strdup_gc(NULL, &data->gc);
    while (!ft_strchr(data->str, q))
    {
        print_pipe(countpipe(data));
        scan = ft_scan_gc(prompt, 1, &data->gc, 0);
        data->str = ft_renew_gc(data->str, scan, 2, &data->gc);
    }
    if (!data->str)
        return (ft_shellerror_gc("malloc error(parsing_last_pipe)\n", data, 0, 1));
    data->str = ft_renew_gc(data->str, tmp, 0, &data->gc);
    free_list(&data->list, &data->gc);
    init_lexer(data, &data->list);
    if (parsing_pipe(data, data->list))
        return (1);
    if (parsing_quote(&data->list, data))
        return (1);
    return (0);
}

int parsing_quote(t_lexst **lex, t_data *data)
{
    t_lexst *list;

    list = *lex;
    while (list)
    {
        if (list->word_type == OPEN_D_QUOTE)
            return (last_quote(data, "dquote> ", '"'));
        else if (list->word_type == OPEN_S_QUOTE)
            return (last_quote(data, "quote> ", '\''));
        list = list->next;
    }
    return (0);
}