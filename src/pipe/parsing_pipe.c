/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/17 14:16:41 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_handler(t_data *data, char *envp[], int i)
{
	pid_t	child;
	int		end_pipe[2];

	// if (!data->str[0])
	// {
	// 	ft_printf_fd(2, "pipex: permission denied: \n");
	// 	exit(127);
	// }
	pipe(end_pipe);
	child = fork();
	if (!child)
	{
		dup2(end_pipe[1], 1);
		close(end_pipe[0]);
		test_parsing_pipe(data, i, envp);
	}
	else
	{
		dup2(end_pipe[0], 0);
		close(end_pipe[1]);
	}
}

void	test_parsing_pipe(t_data *data, int i, char *envp[])
{
	while (data->str[i] && ft_strcmp(data->str[i], "|") != 0)
	{
		if (ft_strcmp(data->str[i], "<<") == 0)
			parsing_heredoc(data, envp);
		if (ft_strcmp(data->str[i], "cat") == 0)
			exec("cat -e", envp);
		if (ft_strcmp(data->str[i], "ls") == 0)
			exec("ls", envp);
		if (ft_strcmp(data->str[i], "wc") == 0)
			exec("wc", envp);
		i++;
	}
	exit(0);
}

void	count_pipe(t_data *data)
{
	int	i;

	i = 0;
	data->pipenb = 0;
	while (data->str[i])
	{
		if (data->str[i][0] == '|')
			data->pipenb++;
		i++;
	}
}

// void    end_pipe(t_data *data, char *envp[])
// {
// 	char *cmd;
	
// 	cmd = ft_strdup("");
// }

void	maybe_pipe(t_data *data, char *envp[])
{
	int	i;
	int	last_pipe;

	i = 0;
	last_pipe = 0;
	count_pipe(data);
	if (data->pipenb > 0)
	{
		while (data->str[i])
		{
			if (((ft_strcmp(data->str[i], "|") == 0) && data->str[i + 1])
				|| !data->str[i + 1])
			{
				pipe_handler(data, envp, last_pipe);
				last_pipe = i + 1;
			}
			i++;
		}
		// if (ft_strcmp(data->str[i - 1], "|") == 0)
		// 	pipe_end(data, envp);
		exec("cat", envp);
	}
}
