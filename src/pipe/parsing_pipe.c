/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:53 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:31 by jdelmott         ###   ########.fr       */
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

int		last_last_pipe(t_data *data)// gerer |> ou |>>
{
	pid_t child;
	char	*gnl;
	int		status;
	
	gnl = ft_strdup_gc("", &data->gc);
	ft_printf_fd(2, "mais enfin\n");
	child = fork();
	ft_printf_fd(2, "la je suis pas d'accord\n");
	if (!child)
	{
		ft_printf_fd(2, "y'a une couille\n");
		while (!gnl[0] || gnl[0] == '\n')
		{
			ft_delone_gc(gnl, &data->gc);
			ft_printf_fd(2,"dsaadsasdads\n");
			print_pipe(data->pipenb);
			gnl = ft_gnl_gc(0, &data->gc);
		}
		ft_printf_fd(2, "%syoupi\n", gnl);
		exit (1);
	}
	waitpid(child, &status, 0);
	ft_printf_fd(2, "ici tout de meme\n");
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
