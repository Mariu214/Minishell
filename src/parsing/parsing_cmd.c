/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:15:54 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/22 10:00:36 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing_built_in(t_data *data, t_lexst **list)
{
	while (*list && (*list)->type == BUILT_IN)
	{
		if (ft_strcmp((*list)->content, "export") == 0)
			return (init_export(data, list));
		else if (ft_strcmp((*list)->content, "unset") == 0)
			return (init_unset(data, list));
		else if (ft_strcmp((*list)->content, "cd") == 0)
			return (init_cd(data, list));
		else if (ft_strcmp((*list)->content, "echo") == 0)
			return (echo(list));
		else if (ft_strcmp((*list)->content, "$?") == 0)
			return (printf("%d: command not found\n", data->dollar), 127);
		else if (ft_strcmp((*list)->content, "pwd") == 0)
			return (print_pwd(data, list));
		else if (ft_strcmp((*list)->content, "env") == 0)
			return (print_env(data, list));
	}
	return (1);
}

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
	if (WIFSIGNALED(signal))
	{
		if (WTERMSIG(signal) == 3)
		{
			printf("Quit (core dumped)\n");
			return (131);
		}
		return (130);
	}
	if (WIFEXITED(signal))
		return (WEXITSTATUS(signal));
	return (0);
}

int	parsing_cmd(t_data *data, t_lexst **list)
{
	char	*cmd;

	if ((*list)->type == BUILT_IN)
		return (parsing_built_in(data, list));
	cmd = ft_strdup_gc((*list)->content, &data->gc);
	(*list) = (*list)->next;
	while ((*list) && (*list)->type == CMD)
	{
		cmd = ft_renew_gc(cmd, " ", 0, &data->gc);
		cmd = ft_renew_gc(cmd, (*list)->content, 0, &data->gc);
		(*list) = (*list)->next;
	}
	return (parsing_cmd_next(cmd, data));
}

int	parsing_cmd_next(char *cmd, t_data *data)
{
    // int     j;
	// char	*temp;

	if (ft_strnstr(cmd, "exit", 5))
		return (255);
	// if (ft_strcmp(cmd, "pwd") == 0)
	// {
	// 	temp = ft_getenv("PWD", data->env);
	// 	printf("%s\n", temp);
	// 	return (0);
	// }
	// else if (ft_strcmp(cmd, "env") == 0)
	// {
	// 	j = 0;
	// 	while (data->env[j])
	// 		printf("%s\n", data->env[j++]);
	// 	return (0);
	// }
    else
        return (parsing_exec(cmd, data));
}