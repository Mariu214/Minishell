/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:49:37 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 16:05:47 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	no_fil_dir(t_command *command, t_data *data)
{
	char	**split;
}

static char	*is_accessible(char *cmd, t_data *data)
{
	t_accessible	temp;

	temp.i = 0;
	temp.all_path = ft_split(ft_getenv("PATH", data->env), ':');
	temp.s_cmd = ft_split(cmd, ' ');
	while (temp.all_path[temp.i])
	{
		temp.join = ft_strjoin(temp.all_path[temp.i], "/");
		temp.path = ft_strjoin(temp.join, temp.s_cmd[0]);
		if (access(temp.path, X_OK | F_OK) == 0)
		{
			free(temp.join);
			free_tab(temp.all_path);
			free_tab(temp.s_cmd);
			return (temp.path);
		}
		free(temp.join);
		free(temp.path);
		temp.i++;
	}
	free_tab(temp.s_cmd);
	free_tab(temp.all_path);
	return (cmd);
}

void	exec(char *cmd, t_data *data)
{
	char		*path;
	t_command	command;

	if (!cmd[0])
		exit(1);
	(void)data;
	// sigaction(SIGINT, &data->sig_child, NULL);
	// sigaction(SIGQUIT, &data->sig_child_slash, NULL);
	command.free = 0;
	command.s_cmd = ft_split_sentence(cmd, ' ', "'");
	path = is_already_path(&command, data);
	if (command.s_cmd[0] == NULL)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: \n");
		exit(127);
	}
	if (path == NULL)
		path = is_accessible(command.s_cmd[0], data);
	if (execve(path, command.s_cmd, data) == -1)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: %s\n", cmd);
		exit(127);
	}
}
