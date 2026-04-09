/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/01 14:48:12 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int cd_make(t_data *data, int i)
// {
// 	char	*temp;
	
// 	if (!data->str[i])
// 		return (printf("no arguments given\n"));
// 	if (chdir(data->str[i]) == -1 )
// 		return (printf("minishell: cd: %s: %s\n", data->str[i], strerror(errno)), 1);
// 	temp = ft_strjoin("PWD=", getcwd(data->current_dir, 4096));
// 	if (!temp)
// 		perror("error");
// 	export(data->env, temp);
// 	free(temp);
// 	return (0);
// }
