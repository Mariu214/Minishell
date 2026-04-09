#ifndef LEXER_H
# define LEXER_H

typedef struct s_data	t_data;

void					parsing_cmd(char *cmd, t_data *data);
int                     test_lexer(t_data *data);
int                     lexing_d_quote(t_data *data, int *i, t_token type);
int                     lexing_s_quote(t_data *data, int *i, t_token type)

#endif