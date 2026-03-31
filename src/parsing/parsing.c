/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:15 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/31 15:06:25 by malaimo          ###   ########.fr       */
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
	return_value = 0;
	if (ft_strcmp(data->str[i], "cd") == 0)
		return_value = cd_make(data, ++i);
	if (data->line[i].str && ft_strnstr(data->line[i].str, "export", 6))
	{
		return_value = init_export(data, i);
		i++;
	}
	if (data->line[i].str && ft_strnstr(data->line[i].str, "unset", 6))
	{
		return_value = init_unset(data, i);
		i++;
	}
	if (data->line[i].str && ft_strnstr(data->line[i].str, "echo", 4))
	{
		return_value = echo(data->line[i].str);
		i++;
	}
	count_pipe(data);
	child = fork();
	if (!child)
	{
		if (ft_strcmp(data->str[i], "$?") == 0)
		{
			printf("%d: command not found\n", data->dollar);
			return_value = 127;
		}
		// else if (ft_strcmp(data->str[i], "pwd") == 0)
		// {
		// 	if (!getcwd(data->current_dir, 4096))
		// 		perror("error");
		// 	else 
		// 		printf("%s\n", data->current_dir);
		// }
		// else if (ft_strcmp(data->str[i], "env") == 0)
		// {
		// 	j = 0;
		// 	while (data->env[j])
        // 		printf("%s\n", data->env[j++]);
		// 	return_value = 0;
		// }
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
		ft_shellerror_gc("", data, return_value);
	}
	else
	{
		waitpid(child, &signal, 0);
		if (WIFEXITED(signal))
			return(WEXITSTATUS(signal));
	}
	return(0);
}
