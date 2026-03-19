/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:34:00 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 14:00:34 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <signal.h>

typedef struct s_sic
{
	pid_t		    content;
	struct s_sic	*next;
	struct s_sic	*previous;
}				t_sic;


void	    here_doc(char *lim, int pipenb, t_data *data);
void		exec(char *cmd, t_data *data);
void        signal_handler(int signum);
void    	init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, struct sigaction *sig_child, struct sigaction *sig_child_slash);
void		print_pipe(int pipenb);

#endif