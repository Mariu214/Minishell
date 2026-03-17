/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:49:37 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/17 14:24:14 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	no_fil_dir(t_command *command)
{
	char	**split;
	char	*path;

	split = ft_split(command->s_cmd[0], '/');
    if (!split)
        return (0);
	else if (ft_strcmp(split[0], "usr") == 0 && ft_strcmp(split[1], "bin") == 0)
	{
		if (access(command->s_cmd[0], X_OK | F_OK) != 0)
		{
			path = ft_strjoin("/", command->s_cmd[0]);
			if (access(path, X_OK | F_OK) != 0)
			{
				command->free = 1;
				free_tab(split);
				free(path);
				ft_printf_fd(2, "minishell: no such file or directory: %s\n",
					command->s_cmd[0]);
				return (127);
			}
		}
	}
	free_tab(split);
	return (0);
}

static char	*is_already_path(t_command *command)
{
	char	*path;

	if (!*command->s_cmd)
		return (NULL);
	if (no_fil_dir(command) == 127)
		return (NULL);
	if (access(command->s_cmd[0], X_OK | F_OK) == 0)
		return (command->s_cmd[0]);
	path = ft_strjoin("/", command->s_cmd[0]);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

static char	*is_accessible(char *cmd, char *envp[])
{
	t_accessible	temp;

	temp.i = 0;
	temp.all_path = ft_split(ft_getenv("PATH", envp), ':');
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

void	exec(char *cmd, char *envp[])
{
	char		*path;
	t_command	command;

	if (!cmd[0])
		exit(1);
	command.free = 0;
	command.s_cmd = ft_split_space(cmd, ' ', "'");
	path = is_already_path(&command);
	if (command.s_cmd[0] == NULL)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: \n");
		exit(127);
	}
	if (path == NULL)
		path = is_accessible(command.s_cmd[0], envp);
	if (execve(path, command.s_cmd, envp) == -1)
	{
		free_tab(command.s_cmd);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: %s\n", cmd);
		exit(127);
	}
}
