/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 13:32:22 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_option(t_lexst *list)
{
	int	i;

	i = 1;
	if (!list->content)
		return (0);
	if (list->content[0] != '-')
		return (0);
	while (list->content[i])
	{
		if (list->content[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	print_echo(t_lexst *list)
{
	while (list && ((list->type >= WORD && list->type <= HEREDOC)))
		list = list->next;
	if (list && (((list)->type >= CMD && (list)->type <= BUILT_IN)))
	{
		printf("%s", (list)->content);
		list = (list)->next;
		if (list && (list->type >= CMD && list->type <= BUILT_IN))
			printf(" ");
	}
}

int		echo(t_lexst **list)
{
	int	option;

	option = 0;
	*list = (*list)->next;
	while (*list && (((*list)->type >= WORD && (*list)->type <= HEREDOC)))
			*list = (*list)->next;
	if (!(*list) || (*list)->type > BUILT_IN)
		return (printf("\n"), 0);
	if (is_option(*list))
	{
		option = 1;
		while (*list && (*list)->type == BUILT_IN && is_option(*list))
			*list = (*list)->next;
	}
	while (*list && (((*list)->type >= CMD && (*list)->type <= BUILT_IN)))
		print_echo(*list);
	if (option == 0)
		printf("\n");
	return (0);
}
