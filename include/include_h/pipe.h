/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:47:57 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 17:02:15 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

typedef struct s_data	t_data;

void					count_pipe(t_data *data);
int						do_pipe(t_data *data, int i);
int						last_pipe(char *cmd, t_data *data, int outfile);
int						last_last_pipe(t_data *data);
// void					test_parsing_pipe(t_data *data, int i, char *envp[]);
// void					pipe_handler(t_data *data, char *envp[], int i);
// void					maybe_pipe(t_data *data, char *envp[]);

#endif