/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:25:42 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/07 10:33:21 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_env(t_data *data, t_lexst **list)
{
	int	j;

	j = 0;
	while (data->env[j])
		printf("%s\n", data->env[j++]);
	*list = (*list)->next;
	return (0);
}
