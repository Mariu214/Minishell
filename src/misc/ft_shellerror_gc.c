/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellerror_gc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:18:04 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/20 09:49:25 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_shellerror_gc(char *str, t_data *data, int out, int mode)
{
	ft_printf_fd(2, "%s", str);
	ft_free_all_gc(&data->gc);
	if (mode == 0)
	{
		free_tab(data->env);
		exit(out);
	}
	else
		return (out);
}
