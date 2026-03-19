#ifndef PARSING_H
# define PARSING_H

typedef struct s_data	t_data;

void					parsing_heredoc(t_data *data, char *lim, char **envp);
void					define_line(t_data *data);
void					parsing(t_data *data, char *envp[]);

#endif