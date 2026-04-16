#ifndef HARDCODED_H
# define HARDCODED_H

int			cd_make(t_data *data, t_lexst **list);

char        *dollar(char *envp[], char *str);

char        **export(char *envp[], char *str);
int 		init_export(t_data *data, t_lexst **list);

char        **unset(char *envp[], char *str);
int 		init_unset(t_data *data, t_lexst **list);

int         echo(char *str);


#endif