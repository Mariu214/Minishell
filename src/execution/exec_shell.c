/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:49:37 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 14:22:23 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> origin/jona
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

static int	no_fil_dir(t_command *command, t_data *data)
{
	char	**split;
	char	*path;

	split = ft_split_gc(command->s_cmd[0], '/', &data->gc);
	if (ft_strcmp(split[0], "usr") == 0 && ft_strcmp(split[1], "bin") == 0)
	{
		if (access(command->s_cmd[0], X_OK | F_OK) != 0)
		{
			path = ft_strjoin_gc("/", command->s_cmd[0], &data->gc);
			if (access(path, X_OK | F_OK) != 0)
			{
				command->free = 1;
				ft_printf_fd(2, "minishell: no such file or directory: %s\n",
					command->s_cmd[0]);
				return (127);
			}
		}
	}
	return (0);
}

static char	*is_already_path(t_command *command, t_data *data)
{
	char	*path;

	if (!*command->s_cmd)
		return (NULL);
	if (no_fil_dir(command, data) == 127)
		return (NULL);
	if (access(command->s_cmd[0], X_OK | F_OK) == 0)
		return (command->s_cmd[0]);
	path = ft_strjoin("/", command->s_cmd[0]);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	return (NULL);
}

static char	*is_accessible(char *cmd, t_data *data)
{
	t_accessible	temp;

	temp.i = 0;
	temp.all_path = ft_split_gc(ft_getenv("PATH", data->env), ':', &data->gc);
	temp.s_cmd = ft_split_gc(cmd, ' ', &data->gc);
	while (temp.all_path[temp.i])
	{
		temp.join = ft_strjoin_gc(temp.all_path[temp.i], "/", &data->gc);
		temp.path = ft_strjoin(temp.join, temp.s_cmd[0]);
		if (access(temp.path, X_OK | F_OK) == 0)
			return (temp.path);
		ft_delone_gc(temp.join, &data->gc);
		free(temp.path);
		temp.i++;
	}
	return (cmd);
}

void	exec(char *cmd, t_data *data)
{
	char		*path;
	t_command	command;
	char		**envcpy;

	if (!cmd[0])
		exit(1);
	(void)data;
	sigaction(SIGINT, &data->sig_child, NULL);
	sigaction(SIGQUIT, &data->sig_child_slash, NULL);
	command.free = 0;
	command.s_cmd = ft_split_sentence(cmd, ' ', "'");
	path = is_already_path(&command, data);
	if (command.s_cmd[0] == NULL)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: \n");
		ft_error_gc("", &data->gc, 127);
	}
	if (path == NULL)
		path = is_accessible(command.s_cmd[0], data);
	envcpy = ft_splitcpy(data->env);
	ft_free_all_gc(&data->gc);
	if (execve(path, command.s_cmd, envcpy) == -1)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: %s\n", cmd);
		ft_error_gc("", &data->gc, 127);
	}
}
