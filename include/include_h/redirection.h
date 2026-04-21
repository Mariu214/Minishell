/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:35 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/21 15:32:52 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

/* OPEN_FILES */
int		open_file(char *fd_arg, int mode);

/* REDIRECTION */
void	input_redirection(char *file1);
void	output_redirection_trunc(char *file);
void	do_redirection(t_data *data, int i);
void	output_redirection_append(char *file);
void	schr_redirection(t_data *data, int i);

#endif