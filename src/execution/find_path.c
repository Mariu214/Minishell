/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:01:02 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 17:41:33 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	no_fil_dir(t_command *command, t_data *data)
{
	char	*path;

	if (ft_strnstr(command->s_cmd[0], "/", 1))
	{
		if (access(command->s_cmd[0], X_OK | F_OK) != 0)
		{
			path = ft_strjoin_gc("/", command->s_cmd[0], &data->gc);
			if (access(path, X_OK | F_OK) != 0)
			{
				command->free = 1;
				ft_printf_fd(2, "%s: %s\n", command->s_cmd[0], strerror(errno));
				ft_shellerror_gc("", data, 127, 0);
			}
		}
	}
	return (0);
}

char	*is_already_path(t_command *command, t_data *data)
{
	char	*path;

	if (!*command->s_cmd || !*command->s_cmd[0])
		return (NULL);
	if (no_fil_dir(command, data) == 127)
		return (NULL);
	if (access(command->s_cmd[0], X_OK | F_OK) == 0)
		return (command->s_cmd[0]);
	path = ft_strjoin_gc("/", command->s_cmd[0], &data->gc);
	if (!path)
		return (NULL);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	return (NULL);
}

char	*is_accessible(char *cmd, t_data *data)
{
	t_accessible	temp;

	temp.i = 0;
	temp.all_path = ft_split_gc(ft_getenv("PATH", data->env), ':', &data->gc);
	temp.s_cmd = ft_strdup_gc(cmd, &data->gc);
	while (temp.all_path[temp.i])
	{
		temp.join = ft_strjoin_gc(temp.all_path[temp.i], "/", &data->gc);
		temp.path = ft_strjoin_gc(temp.join, temp.s_cmd, &data->gc);
		if (access(temp.path, X_OK | F_OK) == 0)
			return (temp.path);
		ft_delone_gc(temp.join, &data->gc);
		ft_delone_gc(temp.path, &data->gc);
		temp.i++;
	}
	return (cmd);
}
