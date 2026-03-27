/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/26 10:11:41 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int cd_make(t_data *data, int i)
{
	if (!data->str[i])
		return (printf("no arguments given\n"));
	if (chdir(data->str[i]) == -1 )
		return (printf("minishell: cd: %s: %s\n", data->str[i], strerror(errno)), 1);
	return (0);
}
