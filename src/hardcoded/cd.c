/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 15:31:04 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int cd_make(t_data *data, t_lexst **list)
{
    *list = (*list)->next;
	if (!(*list) || (*list)->type != BUILT_IN)
		return (printf("no arguments given\n"));
	if (chdir() == -1 )
		return (printf("minishell: cd: %s: %s\n", data->str[i], strerror(errno)), 1);
	temp = ft_strjoin("PWD=", getcwd(data->current_dir, 4096));
	if (!temp)
		perror("error");
	export(data->env, temp);
	free(temp);
	return (0);
}
