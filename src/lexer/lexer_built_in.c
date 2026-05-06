/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:37:19 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 11:26:42 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_built_in(const char *str)
{
	if (ft_strcmp(str, "export") == 0 || ft_strcmp(str, "unset") == 0
		|| ft_strcmp(str, "echo") == 0 || ft_strcmp(str, "pwd") == 0
		|| ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "env") == 0
		|| ft_strcmp(str, "exit") == 0)
		return (1);
	else
		return (0);
}

void	lexing_built_in(t_lexst **list)
{
	t_lexst	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->type == CMD && is_built_in(temp->content))
		{
			while (temp && temp->type == CMD)
			{
				temp->type = BUILT_IN;
				temp = temp->next;
			}
		}
		if (temp)
			temp = temp->next;
	}
}
