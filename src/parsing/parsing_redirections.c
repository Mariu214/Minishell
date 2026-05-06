/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:41:01 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 14:39:51 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing_input(t_lexst *list)
{
	if (!list->next)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	list = list->next;
	if (list->type == OU_APPEND || list->type == PIPE || list->type == INPUT
		|| list->type == OU_TRUNC)
	{
		printf("minishell: syntax error near unexpected token `%c'\n",
			list->content[0]);
		return (2);
	}
	return (input_redirection(list->content));
}

int	parsing_heredoc(t_data *data, t_lexst *list)
{
	if (!list->next)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	list = list->next;
	if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
		|| list->type == HEREDOC)
	{
		printf("minishell: syntax error near unexpected token `%c'\n",
			list->content[0]);
		return (2);
	}
	return (here_doc(list->content, data));
}

int	parsing_ou_trunc(t_lexst *list)
{
	if (!list->next)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	list = list->next;
	if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
		|| list->type == HEREDOC)
	{
		printf("minishell: syntax error near unexpected token `%c'\n",
			list->content[0]);
		return (2);
	}
	return (output_redirection_trunc(list->content));
}

int	parsing_ou_append(t_lexst *list)
{
	if (!list->next)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	list = list->next;
	if (list->type == OU_APPEND || list->type == PIPE || list->type == OU_TRUNC
		|| list->type == HEREDOC)
	{
		printf("minishell: syntax error near unexpected token `%c'\n",
			list->content[0]);
		return (2);
	}
	return (output_redirection_append(list->content));
}
