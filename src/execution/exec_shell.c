/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:33:03 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/07 10:30:07 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*add_quote(char *str, t_data *data)
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

static int	copy_s_cmd(t_lexst **list, t_data *data, char ***s_cmd, int *len)
{
	if (is_there(' ', (*list)->content))
		(*s_cmd)[*len] = add_quote((*list)->content, data);
	else
		(*s_cmd)[*len] = ft_strdup_gc((*list)->content, &data->gc);
	if (!(*s_cmd)[*len])
		return (1);
	(*list) = (*list)->next;
	(*len)++;
	while ((*list) && (((*list)->type >= INPUT && (*list)->type <= HEREDOC)
			|| (*list)->type == WORD))
		(*list) = (*list)->next;
	return (0);
}

static char	**creat_s_cmd(t_lexst **list, t_data *data)
{
	t_lexst	*temp;
	int		len;
	char	**s_cmd;

	temp = (*list);
	len = 0;
	while (temp && temp->type == CMD)
	{
		temp = temp->next;
		len++;
		while (temp && ((temp->type >= INPUT && temp->type <= HEREDOC)
				|| temp->type == WORD))
			temp = temp->next;
	}
	s_cmd = ft_calloc_gc(len + 1, sizeof(*s_cmd), &data->gc);
	if (!s_cmd)
		return (NULL);
	len = 0;
	while ((*list) && (*list)->type == CMD)
		if (copy_s_cmd(list, data, &s_cmd, &len) == 1)
			return (NULL);
	s_cmd[len] = NULL;
	return (s_cmd);
}

static void	exec_fail(t_command command, t_data *data)
{
	if (ft_strnstr(command.s_cmd[0], "/", 1))
	{
		ft_printf_fd(2, "minishell: %s: Is a directory\n");
		ft_shellerror_gc("", data, 126, 0);
	}
	else if (command.free == 0)
	{
		ft_printf_fd(2, "%s: command not found: \n", command.s_cmd[0]);
		ft_shellerror_gc("", data, 127, 0);
	}
}

void	exec(t_lexst **list, t_data *data)
{
	char		*path;
	t_command	command;

	if (!(*list) || !(*list)->content)
		exit(1);
	sigaction(SIGINT, &data->sig_chd, NULL);
	sigaction(SIGQUIT, &data->sig_sh, NULL);
	command.free = 0;
	command.s_cmd = creat_s_cmd(list, data);
	if (!command.s_cmd)
		ft_shellerror_gc("", data, 127, 0);
	path = is_already_path(&command, data);
	if (command.s_cmd[0] == NULL)
	{
		if (command.free == 0)
			ft_printf_fd(2, "minishell: command not found: \n");
		ft_shellerror_gc("", data, 127, 0);
	}
	if (path == NULL)
		path = is_accessible(command.s_cmd[0], data);
	close_fds(data);
	if (execve(path, command.s_cmd, data->env) == -1)
		exec_fail(command, data);
}
