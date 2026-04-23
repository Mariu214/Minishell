#ifndef HARDCODED_H
# define HARDCODED_H

/* CD */
int	cd(t_data *data, char *str);
int	init_cd(t_data *data, t_lexst **list);

/* EXPORT */
int	search_export(t_data *data, char *str, int *i, int *end);
int	fill_export(t_data *data, char *str, int end, int i);
int	export(t_data *data, char *str);
int	init_export(t_data *data, t_lexst **list);

/* UNSET */
int	del_variable(t_data *data, char *str, char *temp, int i);
int	unset(t_data *data, char *str);
int	init_unset(t_data *data, t_lexst **list);

/* ECHO */
int	echo(t_lexst **list);

/* PRINT_ENV */
int	print_env(t_data *data, t_lexst **list);

/* PRINT_PWD */
int	print_pwd(t_data *data, t_lexst **list);

#endif