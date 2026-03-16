/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/16 12:41:48 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_handler(char *str, char *envp[])
{
	pid_t	child;
	int		end_pipe[2];

	if (!str[0])
	{
		ft_printf_fd(2, "pipex: permission denied: \n");
		exit(127);
	}
	pipe(end_pipe);
	child = fork();
	if (!child)
	{
		dup2(end_pipe[1], 1);
		close(end_pipe[0]);
		return ;
	}
	else
	{
		dup2(end_pipe[0], 0);
		close(end_pipe[1]);
	}
}

void	count_pipe(t_data *data)
{
	int	i;

	i = 0;
	data->pipenb = 0;
	while (data->str[i])
	{
		if (data->str[i] == '|')
			data->pipenb++;
		i++;
	}
}
