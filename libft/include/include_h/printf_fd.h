/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:57:39 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 16:00:27 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FD_H
# define PRINTF_FD_H

void				ft_putendl_fd(char *s, int fd);
int					ft_printf_fd(int fd, const char *str, ...);
int					ft_putnbr_fd(int i, int fd);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putnbr_base_fd(unsigned int p, char *base, int fd);
int					ft_putnbr_p_fd(unsigned long s, int fd);
int					ft_putnbr_u_fd(unsigned int s, int fd);
void				ft_putendl_fd(char *s, int fd);

#endif