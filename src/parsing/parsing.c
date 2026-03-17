/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:15 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/17 13:27:05 by jdelmott         ###   ########.fr       */
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
		data->line[i].is_pipe = 0;
		data->line[i].is_redirection = 0;
		i++;
	}
}

void	define_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
		i++;
	init_null(data, i);
	i = 0;
	while (data->str[i])
	{
		if (is_redirection(data->str[i][0]))
		{
			data->line[i].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[i].is_redirection = 1;
		}
		else if (i == 0 && !data->line[i].is_redirection)
		{
			data->line[i].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[i].is_cmd = 1;
		}
		else if ((data->line[i - 1].is_cmd || data->line[i - 1].is_redirection)
			&& !is_redirection(data->str[i][0]) && !is_pipe(data->str[i][0]))
		{
			data->line[i].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[i].is_file = 1;
		}
		else if (is_pipe(data->str[i][0]))
		{
			data->line[i].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[i].is_pipe = 1;
		}
		else
		{
			data->line[i].str = ft_strdup_gc(data->str[i], &data->gc);
			data->line[i].is_cmd = 1;
		}
		i++;
	}
	//     for (int a = 0; data->str[a]; a++)
	//     ft_printf("pipe = %i, redir = %i, file = %i, cmd = %i, %s\n",
		// data->line[a].is_pipe, data->line[a].is_redirection,
		// data->line[a].is_file, data->line[a].is_cmd, data->line[a].str);
}

void	parsing(t_data *data, char *envp[])
{
	int		i;
	pid_t	child;

	i = 0;
	count_pipe(data);
	define_line(data);
	child = fork();
	if (!child)
	{
		while (data->str[i])
		{
			if (ft_strcmp(data->str[i], "exit") == 0)
				ft_free_all_gc(&data->gc);
			if (data->line[i].is_redirection && ft_strcmp(data->line[i].str,
					"<<") == 0)
				parsing_heredoc(data);
			if (data->line[i].is_cmd)
				exec(data->line[i].str, envp);
			i++;
		}
	}
	else
		wait(NULL);
}
