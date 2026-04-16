/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/16 09:19:52 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int cd_make(t_data *data, t_lexst **list)
{
	char    *temp;
	int     return_value;
	
	*list = (*list)->next;
	if (!(*list) || (*list)->type != BUILT_IN)
		return (printf("no arguments given\n"));
	if ((*list)->next && (*list)->next->type == BUILT_IN)
	{
		while (*list && (*list)->type == BUILT_IN)
			*list = (*list)->next;
		return (1);
	}
	if (chdir((*list)->content) == -1 )
		return (printf("minishell: cd: %s: %s\n", (*list)->content, strerror(errno)), 1);
	temp = getcwd(data->current_dir, 4096);
	if (!temp)
		perror("error :");
	temp = ft_strjoin("PWD=", temp);
	if (!temp)
		perror("error :");
	return_value = init_export(data, temp);
	free(temp);
	return (return_value);
}
