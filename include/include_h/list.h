/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:43:10 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/09 11:23:05 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_lexst
{
	char			*content;
	t_token			type;
	struct s_lexst	*next;
	struct s_lexst	*previous;
}					t_lexst;

int					ft_add_node(t_lexst **list, void *content, t_token type);
void				ft_print_list(t_lexst *lexer);

#endif