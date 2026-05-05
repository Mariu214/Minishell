/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:49:37 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/30 10:58:49 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	define_type(t_type type, t_quote quote)
{
	t_token temp;

	temp.type = type;
	temp.quote = quote;
	return (temp);
}