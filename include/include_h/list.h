/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:43:10 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 11:10:36 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

/* DEFINE_TYPE */
t_token	define_type(t_type type, t_quote quote);

/* ADD_NODE */
int		ft_add_node(t_lexst **list, void *content, t_token token, t_gc **gc);

/* DELONE */
int		ft_delone(t_data *data, t_lexst **target);

/* PRINT_LIST */
void	ft_print_list(t_lexst *lexer);
void	print_type(t_type type);

void	free_list(t_lexst **gc, t_gc **g);

#endif
