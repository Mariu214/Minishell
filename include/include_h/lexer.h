#ifndef LEXER_H
# define LEXER_H

typedef struct s_data	t_data;

/* EXPAND_VARIABLE */
char					*expander(t_data *data, char *str, int i, int j);
char					*check_expand(t_data *data, t_lexst **list);

/* LEXER_BUILT_IN */
int						is_built_in(const char *str);
void					lexing_built_in(t_lexst **list);

/* LEXER_CMD */
int						lexing_cmd(t_data *data, int *i, t_lexst **list);

/* LEXER_QUOTES */
int						choose_quote(t_data *data, t_lexst **list, int *i);
int						is_quote(char *src, int j, char q);
int						lexing_d_quote(t_data *data, int *i, t_type type,
							t_lexst **list);
int						lexing_s_quote(t_data *data, int *i, t_type type,
							t_lexst **list);

int     lexing_quote(t_data *data, int *i, t_type type, t_lexst **list);

/* LEXER_REDIRECTIONS */
int						lexing_precise_redirection(t_data *data, char *str,
							t_lexst **list);
int						lexing_redirection(t_data *data, int *i,
							t_lexst **list);

/* LEXER */
int						lexer(t_data *data, t_lexst **list, int *i);
int						init_lexer(t_data *data, t_lexst **list);
int						test_lexer(t_data *data);

/* LEXING_WORD */
int						lexing_word(t_data *data, int *i, t_lexst **list);

/* LEXING_WORD */
int						lexing_pipe(t_data *data, int *i, t_lexst **list);

#endif
