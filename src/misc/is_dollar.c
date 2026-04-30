/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:53:49 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 14:48:58 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_dollar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	find_dollar(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (i);
}