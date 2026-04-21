/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:43:10 by malaimo           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/21 11:05:13 by malaimo          ###   ########.fr       */
=======
/*   Updated: 2026/04/21 15:45:24 by malaimo          ###   ########.fr       */
>>>>>>> marius
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

/* DEFINE_TYPE */
t_token				define_type(t_type type, t_quote quote);

/* ADD_NODE */
int					ft_add_node(t_lexst **list, void *content, t_token token,
						t_gc **gc);

/* DELONE */
int					ft_delone(t_data *data, t_lexst **target);

/* PRINT_LIST */
void				ft_print_list(t_lexst *lexer);

int	do_redirection(t_type redir, t_lexst *file, t_data *data);
int	schr_redirection(t_lexst **list, t_data *data);

#endif
