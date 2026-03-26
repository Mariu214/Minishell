/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:15 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/26 16:54:34 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing(t_data *data)
{
	int		i;
	pid_t	child;
	int		signal;
	int		return_value;
	
	i = 0;
	define_line(data);
	count_pipe(data);
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
					i++;
				if (data->pipedone == data->pipenb)
					return_value = last_pipe(data->line[i].str, data, 1);
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
