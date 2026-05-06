/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:15:54 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:58:21 by jdelmott         ###   ########.fr       */
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
		else if (ft_strcmp((*list)->content, "pwd") == 0)
			return (print_pwd(data, list));
		else if (ft_strcmp((*list)->content, "env") == 0)
			return (print_env(data, list));
		else if (ft_strcmp((*list)->content, "exit") == 0)
			return (ft_exit(data, list), 0);
	}
	return (1);
}

static int	parsing_exec(t_lexst **list, t_data *data)
{
	pid_t	child;
	int		signal;

	signal = 0;
	child = fork();
	if (!child)
		exec(list, data);
	else
		wait(NULL);
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
	if ((*list)->type == BUILT_IN)
		return (parsing_built_in(data, list));
	if (ft_strnstr((*list)->content, "exit", 5))
		return (255);
	else
		return (parsing_exec(list, data));
}
