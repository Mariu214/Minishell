/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:47:57 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/21 15:27:35 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

typedef struct s_data	t_data;

// void					count_pipe(t_data *data);
// int						do_pipe(t_data *data, int i);
// int						last_pipe(char *cmd, t_data *data, int outfile);
// int						last_last_pipe(t_data *data);
// char					*rm_nl_gc(char *old, t_data *data);

/* LAST_PIPE */
int						is_last_pipe(char *line);

/* PARSING_PIPE */
int						last_pipe(t_data *data, t_lexst **list);
int						apply_pipe(t_data *data, t_lexst **list);
int						find_pipe(t_data *data);
int						parsing_pipe(t_data *data, t_lexst *list);

/* PIPENB */
int						countpipe(t_data *data);
void					print_pipe(int pipenb);

#endif