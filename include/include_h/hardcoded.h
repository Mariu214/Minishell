#ifndef HARDCODED_H
# define HARDCODED_H

int         init_cd(t_data *data, t_lexst **list);

char        *dollar(char *envp[], char *str);

int         export(t_data *data, char *str);
int         init_export(t_data *data, t_lexst **list);

int         replace_export(t_data *data, char *str, int i);
int         replace_env(t_data *data, char *str, int i);
int         check_env(t_data *data, char *str, int *i);
int         fill_env(t_data *data, char *str, int i);
int         fill_export(t_data *data, char *str, int end, int i);

int         del_variable(t_data *data, char *str, char *temp, int i);
int         unset(t_data *data, char *str);
int 		init_unset(t_data *data, t_lexst **list);

int         echo(char *str);


#endif