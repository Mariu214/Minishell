/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:59:41 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/30 10:34:05 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void define_file(t_data *data, t_lexer *lex)
{
    lex->done = 0;
    lex->k = 0;
    while (data->str[lex->i][lex->k] && !is_pipe(data->str[lex->i][lex->k]) && !is_redirection(data->str[lex->i][lex->k]))
    {
		lex->k++;
        if (is_pipe(data->str[lex->i][lex->k]) || is_redirection(data->str[lex->i][lex->k]))
        {
            data->line[lex->j].str = ft_renew_gc(data->line[lex->j].str, ft_split_gc(data->str[lex->i], data->str[lex->i][lex->k], &data->gc)[0], &data->gc);
            lex->temp = ft_strdup_gc(&data->str[lex->i][lex->k], &data->gc);
            ft_delone_gc(data->str[lex->i], &data->gc);
            data->str[lex->i] = ft_strdup_gc(lex->temp, &data->gc);
            ft_delone_gc(lex->temp, &data->gc);
            lex->done = 1;
            break;
        }
    }
}

static void	define_redirection(t_data *data, t_lexer *lex)
{
	lex->k = 0;
	while (data->str[lex->i][lex->k] && is_redirection(data->str[lex->i][lex->k]))
	{
		lex->k++;
		if (data->str[lex->i][lex->k]
			&& !is_redirection(data->str[lex->i][lex->k]))
		{
            data->line[lex->j].str = ft_strjoin_gc(ft_split_gc(data->str[lex->i], data->str[lex->i][lex->k], &data->gc)[0], " ", &data->gc);
            lex->temp = ft_strdup_gc(&data->str[lex->i][lex->k], &data->gc);
            ft_delone_gc(data->str[lex->i], &data->gc);
            data->str[lex->i] = ft_strdup_gc(lex->temp, &data->gc);
            ft_delone_gc(lex->temp, &data->gc);
            define_file(data, lex);
            if (lex->done == 0 && lex->k == 0)
                lex->i++;
			break;
		}
	}
	if (!data->line[lex->j].str)
	{
		data->line[lex->j].str = ft_strdup_gc(data->str[lex->i], &data->gc);
		lex->i++;
	}
	if (lex->done == 0)
	{
		if (!is_there(' ', data->line[lex->j].str))
			data->line[lex->j].str = ft_renew_gc(data->line[lex->j].str, " ", &data->gc);
		if (data->str[lex->i])
			define_file(data, lex);
		if (lex->done == 0 && data->str[lex->i])
		{
			data->line[lex->j].str = ft_renew_gc(data->line[lex->j].str, data->str[lex->i], &data->gc);
			lex->i++; 
		}
	}
	data->line[lex->j].is_redirection = 1;
	lex->j++;
	lex->done = 0;
}

static void	define_pipe(t_data *data, t_lexer *lex)
{
	lex->k = 0;
	if (data->str[lex->i][1])
	{
		while (is_pipe(data->str[lex->i][lex->k]))
		{
			lex->k++;
			if (!is_pipe(data->str[lex->i][lex->k]))
			{
				data->line[lex->j].str = ft_strdup_gc(ft_split_gc(data->str[lex->i],
							data->str[lex->i][lex->k], &data->gc)[0],
						&data->gc);
				lex->temp = ft_strdup_gc(&data->str[lex->i][lex->k], &data->gc);
				ft_delone_gc(data->str[lex->i], &data->gc);
				data->str[lex->i] = ft_strdup_gc(lex->temp, &data->gc);
				ft_delone_gc(lex->temp, &data->gc);
				lex->done = 1;
			}
		}
	}
	if (lex->done == 0)
	{
		data->line[lex->j].str = ft_strdup_gc(data->str[lex->i], &data->gc);
		lex->i++;
	}
	data->line[lex->j].is_pipe = 1;
	lex->j++;
	lex->done = 0;
}

static void	define_command_end(t_data *data, t_lexer *lex)
{
	lex->temp2 = ft_strdup_gc(data->str[lex->i], &data->gc);
	while (data->str[lex->i][lex->k] && !is_pipe(data->str[lex->i][lex->k])
		&& !is_redirection(data->str[lex->i][lex->k]))
	{
		lex->k++;
		if (is_pipe(data->str[lex->i][lex->k])
			|| is_redirection(data->str[lex->i][lex->k]))
		{
			ft_delone_gc(lex->temp2, &data->gc);
			lex->temp2 = ft_strdup_gc(ft_split_gc(data->str[lex->i],
						data->str[lex->i][lex->k], &data->gc)[0], &data->gc);
			lex->temp = ft_strdup_gc(&data->str[lex->i][lex->k], &data->gc);
			ft_delone_gc(data->str[lex->i], &data->gc);
			data->str[lex->i] = ft_strdup_gc(lex->temp, &data->gc);
			ft_delone_gc(lex->temp, &data->gc);
			lex->done = 1;
			break ;
		}
	}
	if (data->line[lex->j].str)
		data->line[lex->j].str = ft_renew_gc(data->line[lex->j].str, lex->temp2,
				&data->gc);
	else
		data->line[lex->j].str = ft_strdup_gc(lex->temp2, &data->gc);
	ft_delone_gc(lex->temp2, &data->gc);
}

static void	define_command(t_data *data, t_lexer *lex)
{
	lex->k = 0;
	define_command_end(data, lex);
	if (lex->done == 0)
	{
		lex->i++;
		while (data->str[lex->i] && !is_pipe(data->str[lex->i][0])
			&& !is_redirection(data->str[lex->i][0]))
		{
			data->line[lex->j].str = ft_renew_gc(data->line[lex->j].str, " ",
					&data->gc);
			lex->k = 0;
			define_command_end(data, lex);
			if (lex->done == 0)
				lex->i++;
			else
				break ;
		}
	}
	data->line[lex->j].is_cmd = 1;
	lex->j++;
	lex->done = 0;
}

void	define_line(t_data *data)
{
	t_lexer	lex;

	lex.i = -1;
	lex.len = 0;
	lex.done = 0;
	while (data->str[lex.i++])
		lex.len += ft_strlen(data->str[lex.i]);
	init_null(data, lex.len);
	lex.i = 0;
	lex.j = 0;
	while (data->str[lex.i])
	{
		if (data->str[lex.i] && is_redirection(data->str[lex.i][0])) // gerer >> , >>,>> = 3 fois plus youpi
			define_redirection(data, &lex);
		else if (data->str[lex.i] && is_pipe(data->str[lex.i][0]))
			define_pipe(data, &lex);
		else if (data->str[lex.i] && !is_pipe(data->str[lex.i][0])
			&& !is_redirection(data->str[lex.i][0]))
			define_command(data, &lex);
	}
	// for (int a = 0; data->line[a].str; a++)
	// 	ft_printf("pipe = %i, redir = %i, file = %i, cmd = %i, %s\n",
	// 		data->line[a].is_pipe, data->line[a].is_redirection,
	// 		data->line[a].is_file, data->line[a].is_cmd, data->line[a].str);
}
