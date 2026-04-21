#ifndef PARSING_H
# define PARSING_H

# include "list.h"

typedef struct s_data	t_data;


void					parsing_heredoc(t_data *data, char *lim);
// void					define_line(t_data *data);
// int						parsing(t_data *data);
// int						do_comm(t_data *data, int i);
// int						is_pipe(char c);
// int						is_redirection(char c);
// void					init_null(t_data *data, int size);

int	    parsing_cmd(t_data *data, t_lexst **list);
int    parsing_cmd_next(char *cmd, t_data *data);
void    parser_built_in(t_lexst **list);
int init_parser(t_data *data);

int     find_pipe(t_data *data);



int parsing_quote(t_lexst **lex, t_data *data);



#endif