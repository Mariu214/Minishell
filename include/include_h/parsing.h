#ifndef PARSING_H
# define PARSING_H

# include "list.h"

typedef struct s_data	t_data;

/* PARSING */
int						init_parser(t_data *data);

/* PARSING_CMD*/
int						parsing_built_in(t_data *data, t_lexst **list);
int						parsing_cmd(t_data *data, t_lexst **list);
int						parsing_cmd_next(char *cmd, t_data *data);

/* PARSING_HEREDOC */
void					parsing_heredoc(t_data *data, char *lim);

#endif