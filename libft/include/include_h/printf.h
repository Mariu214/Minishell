/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:55:59 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:56:42 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

int					ft_putnbr(int i);
int					ft_putnbr_base(unsigned int i, char *base);
int					ft_putnbr_p(unsigned long s);
int					ft_putnbr_u(unsigned int i);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_printf(const char *str, ...);

#endif