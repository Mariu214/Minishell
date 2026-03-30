#ifndef HARDCODED_H
# define HARDCODED_H

int 		cd_make(t_data *data, int i);
char        **unset(char *envp[], char *str);
char        **export(char *envp[], char *str);
char        *dollar(char *envp[], char *str);

#endif