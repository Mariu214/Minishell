/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:19:24 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 10:58:06 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_pwd(t_data *data, t_lexst **list)
{
	*list = (*list)->next;
	if (!getcwd(data->current_dir, 4096))
		return (perror("error"), 1);
	else
		printf("%s\n", data->current_dir);
	return (0);
}
