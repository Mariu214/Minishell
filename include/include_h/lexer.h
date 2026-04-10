#ifndef LEXER_H
# define LEXER_H

typedef struct s_data	t_data;

void					parsing_cmd(char *cmd, t_data *data);
int                     test_lexer(t_data *data);
int                     lexing_d_quote(t_data *data, int *i, t_token type);
int                     lexing_s_quote(t_data *data, int *i, t_token type);
int     lexing_sort(t_data *data, int *i, int jsp);
int     lexing_precise_redirection(t_data *data, char *str);
int     lexer(t_data *data);
int		lexing_pipe(t_data *data, int *i);
int		lexing_redirection(t_data *data, int *i);
int		lexing_cmd(t_data *data, int *i);
int		lexing_word(t_data *data, int *i);



#endif