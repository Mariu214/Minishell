/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:15:54 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/30 09:32:59 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parsing_cmd(char *cmd, t_data *data)
{
    int     j;

	if (ft_strcmp(cmd, "pwd") == 0)
	{
		if (!getcwd(data->current_dir, 4096))
			perror("error");
		else
			printf("%s\n", data->current_dir);
	}
	else if (ft_strcmp(cmd, "env") == 0)
	{
		j = 0;
		while (data->env[j])
			printf("%s\n", data->env[j++]);
		// return_value = 0;
	}
    else
        exec(cmd, data);
}