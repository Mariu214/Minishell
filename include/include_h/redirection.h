/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:35 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/16 12:45:44 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

int	open_file(char *fd_arg, int mode);
int	input_redirection(char *file1);
int	output_redirection_trunc(char *file);
int	output_redirection_append(char *file);

#endif