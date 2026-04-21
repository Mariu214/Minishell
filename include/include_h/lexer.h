#ifndef LEXER_H
# define LEXER_H

typedef struct s_data	t_data;

int                     test_lexer(t_data *data);
int                     lexing_d_quote(t_data *data, int *i, t_type type, t_lexst **list);
int                     lexing_s_quote(t_data *data, int *i, t_type type, t_lexst **list);
int     lexing_sort(t_data *data, int *i, int jsp, t_lexst **list);
int     lexing_precise_redirection(t_data *data, char *str, t_lexst **list);
int     lexer(t_data *data, t_lexst **list);
int		lexing_pipe(t_data *data, int *i, t_lexst **list);
int		lexing_redirection(t_data *data, int *i, t_lexst **list);
int		lexing_cmd(t_data *data, int *i, t_lexst **list);
void	lexing_built_in(t_lexst **list);
int		lexing_word(t_data *data, int *i, t_lexst **list);
int     check_expand(t_data *data, t_lexst **list);


#endif
