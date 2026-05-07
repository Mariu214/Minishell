/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:30:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/07 10:37:06 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_data *data, t_lexst **list)
{
	*list = (*list)->next;
	if (!list || (*list)->type != BUILT_IN)
		ft_shellerror_gc("exit\n", data, 0, 0);
	if ((*list)->next && (*list)->next->type == BUILT_IN)
		ft_shellerror_gc("exit\ntoo many arguments\n", data, 1, 0);
	ft_shellerror_gc("exit\n", data, ft_atoll((*list)->content, data) % 256, 0);
}
