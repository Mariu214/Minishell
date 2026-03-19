/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 17:32:53 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		do_comm(t_data *data, int i)
{
	pid_t	child;
	int		status;

	child = fork();
	if (!child)
	{
		if (ft_strcmp(data->str[i], "exit") == 0)
			ft_free_all_gc(&data->gc);
		if (data->line[i].is_redirection
			&& ft_strcmp(ft_split_gc(data->line[i].str, ' ', &data->gc)[0],
				"<<") == 0)
			parsing_heredoc(data, ft_split_gc(data->line[i].str, ' ',
					&data->gc)[1]);
		if (data->line[i].is_cmd)
			exec(data->line[i].str, data);
		ft_error_gc("", &data->gc, 0);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

char	*rm_nl_gc(char *old, t_data *data)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc_gc(sizeof(char), ft_strlen(old), &data->gc);
	while (old[i] && old[i] != '\n')
	{
		new[i] = old[i];
		i++;	
	}
	new[i] = '\0';
	ft_delone_gc(old, &data->gc);
	return (new);
}

int		last_last_pipe(t_data *data)// gerer |> ou |>>
{
	pid_t child;
	char	*gnl;
	int		status;
	
	gnl = ft_strdup_gc("", &data->gc);
	child = fork();
	dup2(1, 1);
	if (!child)
	{
		while (!gnl[0] || gnl[0] == '\n')
		{
			ft_delone_gc(gnl, &data->gc);
			print_pipe(data->pipenb - 1);
			ft_printf_fd(2, "pipe> ");
			gnl = ft_gnl_gc(1, &data->gc);
		}
		gnl = rm_nl_gc(gnl, data);
		last_pipe(gnl, data, 1);
		exit (0);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int		last_pipe(char *cmd, t_data *data, int outfile)
{
	pid_t	child;
	int		status;

	// if (!cmd[0])
	// {
	// 	ft_printf_fd(2, "pipex: permission denied: \n");
	// 	exit(127);
	// }
	child = fork();
	if (!child)
	{
		dup2(outfile, 1);
		exec(cmd, data);
	}
	else
	{
		waitpid(child, &status, 0);
		if (WIFEXITED(status))
			return(WEXITSTATUS(status));
		return (0);
	}
	return (0);
}

int		do_pipe(t_data *data, int i)
{
	pid_t	child;
	int		status;
	int		end_pipe[2];

	// if (!cmd[0])
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
		exec(data->line[i].str, data);
	}
	else
	{
		dup2(end_pipe[0], 0);
		close(end_pipe[1]);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
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
	if (data->pipenb > 0)
		data->pipedone = 0;
	else
		data->pid = -1;
}
