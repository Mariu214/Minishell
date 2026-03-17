#ifndef PARSING_H
# define PARSING_H

typedef struct s_data	t_data;

void					init_parsing(t_data *data, char **envp);
void					parsing_heredoc(t_data *data);
void					define_line(t_data *data);
void					parsing(t_data *data, char *envp[]);

#endif