/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:09:29 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:57:48 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_type(t_type type)
{
	if (type == CMD)
		ft_printf_fd(2, "CMD, ");
	else if (type == WORD)
		ft_printf_fd(2, "WORD, ");
	else if (type == OU_TRUNC)
		ft_printf_fd(2, "OU_TRUNC, ");
	else if (type == INPUT)
		ft_printf_fd(2, "INPUT, ");
	else if (type == OU_APPEND)
		ft_printf_fd(2, "OU_APPEND, ");
	else if (type == HEREDOC)
		ft_printf_fd(2, "HEREDOC, ");
	else if (type == PIPE)
		ft_printf_fd(2, "PIPE, ");
	else if (type == BUILT_IN)
		ft_printf_fd(2, "BUILT_IN, ");
	else
		ft_printf_fd(2, "ERROR = %i\n", type);
}

static void	print_type_word(t_quote word)
{
	if (word == WRD)
		ft_printf_fd(2, "WORD\n");
	else if (word == OPEN_D_QUOTE)
		ft_printf_fd(2, "OPEN_D_QUOTE\n");
	else if (word == CLOSED_D_QUOTE)
		ft_printf_fd(2, "CLOSED_D_QUOTE\n");
	else if (word == OPEN_S_QUOTE)
		ft_printf_fd(2, "OPEN_S_QUOTE\n");
	else if (word == CLOSED_S_QUOTE)
		ft_printf_fd(2, "CLOSED_S_QUOTE\n");
	else
		ft_printf_fd(2, "ERROR\n");
}

void	ft_print_list(t_lexst *lexer)
{
	t_lexst	*temp;

	temp = lexer;
	while (temp)
	{
		ft_printf_fd(2, "%s, ", temp->content);
		print_type(temp->type);
		print_type_word(temp->word_type);
		temp = temp->next;
	}
}
