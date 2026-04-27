/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:33:03 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/27 10:05:07 by jdelmott         ###   ########.fr       */
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
				ft_printf_fd(2, "%s: %s\n", command->s_cmd[0], strerror(errno));
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
	if (!path)
		return (NULL);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

static char	*is_accessible(char *cmd, t_data *data)
{
	t_accessible	temp;

	temp.i = 0;
	temp.all_path = ft_split_gc(ft_getenv("PATH", data->env), ':', &data->gc);
	temp.s_cmd = ft_strdup_gc(cmd, &data->gc);
	while (temp.all_path[temp.i])
	{
		temp.join = ft_strjoin_gc(temp.all_path[temp.i], "/", &data->gc);
		temp.path = ft_strjoin(temp.join, temp.s_cmd);
		if (access(temp.path, X_OK | F_OK) == 0)
			return (temp.path);
		ft_delone_gc(temp.join, &data->gc);
		free(temp.path);
		temp.i++;
	}
	return (cmd);
}

static char *add_quote(char *str, t_data *data)
{
	char	*quoted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quoted = ft_calloc_gc(sizeof(char), ft_strlen(str) + 3, &data->gc);
	if (!quoted)
		return (NULL);
	quoted[i] = '\'';
	i++;
	while (str[j])
	{
		quoted[i] = str[j];
		i++;
		j++;
	}
	quoted[i] = '\'';
	i++;
	quoted[i] = '\0';
	return (quoted);
}

static char **creat_s_cmd(t_lexst **list, t_data *data)
{
	t_lexst *temp;
	int	len;
	char	**s_cmd;

	temp = (*list);
	len = 0;
	while (temp && temp->type == CMD)
	{
		temp = temp->next;
		len++;
	}
	s_cmd = ft_calloc_gc(sizeof(char *), len + 1, &data->gc);
	if (!s_cmd)
		return (NULL);
	len = 0;
	while ((*list) && (*list)->type == CMD)
	{
		if (is_there(' ', (*list)->content))
			s_cmd[len] = add_quote((*list)->content, data);
		else
			s_cmd[len] = ft_strdup_gc((*list)->content, &data->gc);
		if (!s_cmd[len])
			return (NULL);
		(*list) = (*list)->next;
		len++;
	}
	s_cmd[len] = NULL;
	return (s_cmd);
}

void	exec(t_lexst **list, t_data *data)
{
	char		*path;
	char	**cmd;
	t_command	command;

	if (!(*list) || !(*list)->content)
		exit(1);
	sigaction(SIGINT, &data->sig_child, NULL);
	sigaction(SIGQUIT, &data->sig_child_slash, NULL);
	command.free = 0;
	command.s_cmd = creat_s_cmd(list, data);
	// for (int i = 0; command.s_cmd[i]; i++)
	// 	ft_printf_fd(2, "%s\n", command.s_cmd[i]);
	path = is_already_path(&command, data);
	if (command.s_cmd[0] == NULL)
	{
		free_tab(command.s_cmd);
		if (path)
			free(path);
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: \n");
		ft_shellerror_gc("", data, 127, 0);
	}
	if (path == NULL)
		path = is_accessible(command.s_cmd[0], data);
	cmd = ft_splitdup(command.s_cmd);
	ft_free_all_gc(&data->gc);
	if (execve(path, cmd, data->env) == -1)
	{
		if (path)
			free(path);
		if (command.free == 0)
			ft_printf_fd(2, "%s: command not found: \n", cmd[0]);
		free_tab(cmd);
		ft_shellerror_gc("", data, 127, 0);
	}
}
