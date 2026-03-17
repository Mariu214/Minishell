/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:35 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/17 15:13:28 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

int	open_file(char *fd_arg, int mode);
void	input_redirection(char *file1);
void    output_redirection_trunc(char *file);
void    do_redirection(t_data *data);
void    output_redirection_append(char *file);

#endif