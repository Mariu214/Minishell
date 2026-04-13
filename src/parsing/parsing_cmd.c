/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:15:54 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/13 11:09:58 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int		parsing_exec(char *cmd, t_data *data)
{
	pid_t	child;
	int		signal;

	signal = 0;
	child = fork();
	if (!child)
		exec(cmd, data);
	else
		waitpid(child, &signal, 0);
	if (WIFEXITED(signal))
		return (WEXITSTATUS(signal));
	return (0);
}

int	parsing_cmd(t_data *data)
{
	char	*cmd;
	t_lexst	*temp;

	temp = data->list;
	while (temp->previous && temp->previous->type == CMD)
		temp = temp->previous;
	cmd = ft_strdup_gc(temp->content, &data->gc);
	temp = temp->next;
	while (temp && temp->type == CMD)
	{
		cmd = ft_renew_gc(cmd, " ", &data->gc);
		cmd = ft_renew_gc(cmd, temp->content, &data->gc);
		temp = temp->next;
	}
	return (parsing_cmd_next(cmd, data));
}

int	parsing_cmd_next(char *cmd, t_data *data)
{
    int     j;
	char	*temp;

	if (ft_strnstr(cmd, "exit", 5))
		return (255);
	if (ft_strcmp(cmd, "pwd") == 0)
	{
		temp = ft_getenv("PWD", data->env);
		printf("%s\n", temp);
		return (0);
	}
	else if (ft_strcmp(cmd, "env") == 0)
	{
		j = 0;
		while (data->env[j])
			printf("%s\n", data->env[j++]);
		return (0);
	}
    else
        return (parsing_exec(cmd, data));
}