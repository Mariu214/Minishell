/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:35 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/22 09:35:26 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

/* OPEN_FILES */
int		open_file(char *fd_arg, int mode);

/* REDIRECTION */
int 	input_redirection(char *file1);
int 	output_redirection_append(char *file);
int	    do_redirection(t_type redir, t_lexst *file, t_data *data);
int	    output_redirection_trunc(char *file);
int	    schr_redirection(t_lexst **list, t_data *data);

#endif