/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:47:57 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 18:07:08 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

typedef struct s_data	t_data;

void					count_pipe(t_data *data);
int						do_pipe(t_data *data, int i);
int						last_pipe(char *cmd, t_data *data, int outfile);
int						last_last_pipe(t_data *data);
char					*rm_nl_gc(char *old, t_data *data);

#endif