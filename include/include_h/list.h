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

#endif
