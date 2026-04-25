#ifndef PARSING_H
# define PARSING_H

# include "list.h"

typedef struct s_data	t_data;

/* PARSING */
int						init_parser(t_data *data);

/* PARSING_CMD*/
int						parsing_built_in(t_data *data, t_lexst **list);
int						parsing_cmd(t_data *data, t_lexst **list);
int						parsing_cmd_next(t_lexst **list, t_data *data);

// /* PARSING_HEREDOC */
// void					parsing_heredoc(t_data *data, char *lim);

/* PARSING_REDIRECTIONS */
int parsing_input(t_lexst *list);
int parsing_heredoc(t_data *data, t_lexst *list);
int parsing_ou_trunc(t_lexst *list);
int parsing_ou_append(t_lexst *list);

int parsing_quote(t_lexst **lex, t_data *data);



#endif