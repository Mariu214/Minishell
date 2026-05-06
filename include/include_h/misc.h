#ifndef MISC_H
# define MISC_H

int	ft_shellerror_gc(char *str, t_data *data, long out, int mode);
int	close_fds(t_data *data);
int	is_dollar(char *str);
int	find_dollar(char *str);
int is_minus(char *str);
long	ft_atoll(const char *nptr, t_data *data);

#endif
