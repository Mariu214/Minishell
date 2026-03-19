/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:15 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 09:38:54 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_redirection(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

void	init_null(t_data *data, int size)
{
	int	i;

	i = 0;
	data->line = ft_calloc_gc(sizeof(t_cmd), (size + 1), &data->gc);
	while (i <= size)
	{
		data->line[i].is_cmd = 0;
		data->line[i].is_file = 0;
		data->line[i].is_pipe = 0;
		data->line[i].is_redirection = 0;
		i++;
	}
}

void	define_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
		i++;
	init_null(data, i);
	i = 0;
	j = 0;
	while (data->str[i])
	{
		if (data->str[i] && is_redirection(data->str[i][0]))
		{
			data->line[j].str = ft_strdup_gc(data->str[i], &data->gc);
			if (data->str[i] && ft_strcmp(data->str[i], "<<") == 0)
			{
				data->line[j].str = ft_renew_gc(data->line[i].str, " ",
						&data->gc);
				data->line[j].str = ft_renew_gc(data->line[i].str, data->str[i
						+ 1], &data->gc);
				i++;
			}
			i++;
			data->line[j].is_redirection = 1;
			j++;
		}
		else if (data->str[i] && (j > 0 && data->line[j - 1].is_redirection)
			&& !ft_strnstr(data->line[j - 1].str, "<<", 3))
		{
			data->line[j].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[j].is_file = 1;
			j++;
			i++;
		}
		else if (data->str[i] && is_pipe(data->str[i][0]))
		{
			data->line[j].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[j].is_pipe = 1;
			i++;
			j++;
		}
		else if (data->str[i] && !is_pipe(data->str[i][0])
			&& !is_redirection(data->str[i][0]))
		{
			data->line[j].str = ft_strdup_gc(data->str[i], &data->gc);
			i++;
			while (data->str[i] && !is_pipe(data->str[i][0])
				&& !is_redirection(data->str[i][0]))
			{
				data->line[j].str = ft_renew_gc(data->line[j].str, " ",
						&data->gc);
				data->line[j].str = ft_renew_gc(data->line[j].str, data->str[i],
						&data->gc);
				i++;
			}
			data->line[j].is_cmd = 1;
			j++;
		}
	}
	// for (int a = 0; data->str[a]; a++)
	// 	ft_printf("pipe = %i, redir = %i, file = %i, cmd = %i, %s\n",
	// 		data->line[a].is_pipe, data->line[a].is_redirection,
	// 		data->line[a].is_file, data->line[a].is_cmd, data->line[a].str);
}

void	parsing(t_data *data)
{
	int		i;
	pid_t	child;
	int		signal;

	i = 0;
	count_pipe(data);
	define_line(data);
	child = fork();
	if (!child)
	{
		do_redirection(data);
		while (data->str[i])
		{
			if (ft_strcmp(data->str[i], "exit") == 0)
				ft_free_all_gc(&data->gc);
			if (data->line[i].is_redirection
				&& ft_strcmp(ft_split_gc(data->line[i].str, ' ', &data->gc)[0],
					"<<") == 0)
				parsing_heredoc(data, ft_split_gc(data->line[i].str, ' ',
						&data->gc)[1]);
			if (data->line[i].is_cmd)
				exec(data->line[i].str, data->env);
			i++;
		}
		ft_error_gc("", &data->gc, 0);
	}
	else
		waitpid(child, &signal, 0);
}
