/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:18:04 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/30 13:45:00 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_error_gc(char *str, t_gc **gc, int out)
{
	ft_printf_fd(2, "%s", str);
	ft_free_all_gc(gc);
	exit(out);
}
