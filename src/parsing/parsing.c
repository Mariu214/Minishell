/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:15 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/24 17:33:37 by jdelmott         ###   ########.fr       */
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
		if (data->str[i] && is_redirection(data->str[i][0]))// gerer |> et |>> // aussi >> , >>,>> = 3 fois plus youpi
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

int	parsing(t_data *data)
{
	int		i;
	pid_t	child;
	int		signal;
	int		return_value;
	
	i = 0;
	count_pipe(data);
	define_line(data);
	child = fork();
	if (!child)
	{
		if (ft_strcmp(data->str[i], "$?") == 0)
		{
			printf("%d: command not found\n", data->dollar);
			return_value = 0;
		}
		else
		{
			while (data->line[i].str)
			{
				schr_redirection(data, i);
				if (data->line[i].is_redirection)
				{
					i++;
					if (data->line[i].str && data->line[i].is_file)
						i++;
				}
				if (data->pipedone == data->pipenb)
					return_value = last_pipe(data->line[i].str, data, 1);
				ft_printf_fd(2, "%i, %i\n", data->pipenb, i);
				if (!data->pipenb) // if > il refuse de rentrer ici cet enfoiree sauf sans trunc c'est un delire
					return_value = do_comm(data, i);
				else
				{
					if (data->line[i].is_pipe)
					{
						return_value = do_pipe(data, i - 1);
						data->pipedone++;
						if (!data->line[i + 1].str)
							return_value = last_last_pipe(data);
					}
				}
				// if (data->line[i + 1].str && data->line[i + 1].is_file)
				// 	i++;
				i++;
			}
		}
		ft_error_gc("", &data->gc, return_value);
	}
	else
	{
		waitpid(child, &signal, 0);
		if (WIFEXITED(signal))
		{
			if (WEXITSTATUS(signal) == 131)
				printf("\nQuit (core dumped)\n");
			return(WEXITSTATUS(signal));
		}
		if (WIFSIGNALED(signal))
		{
			if (WTERMSIG(signal) == 3)
			{
				printf("Quit (core dumped)\n");
				return (131);
			}
			return (130);
		}
	}
	return(0);
}
