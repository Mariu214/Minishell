/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:07:59 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 14:11:55 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

int		ft_shellerror_gc(char *str, t_data *data, long out, int mode);
int		close_fds(t_data *data);
int		is_dollar(char *str);
int		find_dollar(char *str);
int		is_minus(char *str);
long	ft_atoll(const char *nptr, t_data *data);

void	init_loop(t_data *data, char **line);
void	init_data(t_data *data, int argc, char *argv[], char *envp[]);

#endif
