/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:43:10 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 10:32:39 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_lexst
{
	char			*content;
	t_type			type;
	t_quote			word_type;
	struct s_lexst	*next;
	struct s_lexst	*previous;
}					t_lexst;

typedef struct e_token
{
	t_type			type;
	t_quote			quote;
}					t_token;

int					ft_add_node(t_lexst **list, void *content, t_token token,
						t_gc **gc);
void				ft_print_list(t_lexst *lexer);
t_token				define_type(t_type type, t_quote quote);

int		parser(t_data *data, t_lexst **list);
int     parsing_pipe(t_data *data, t_lexst *list);

#endif
