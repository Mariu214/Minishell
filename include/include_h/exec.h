/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:34:00 by jdelmott          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/20 13:46:08 by jdelmott         ###   ########.fr       */
=======
/*   Updated: 2026/04/21 15:45:18 by malaimo          ###   ########.fr       */
>>>>>>> marius
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

/* EXEC_SHELL */
void	exec(char *cmd, t_data *data);

<<<<<<< HEAD
int	    here_doc(char *lim, t_data *data);
void		exec(char *cmd, t_data *data);
=======
/* HERE_DOC */
void	    here_doc(char *lim, int pipenb, t_data *data);

/* SIGNALS_HANDLERS */
void    	child_quit(int signum);
void    	signal_quit(int signum);
>>>>>>> marius
void        signal_handler(int signum);
void    	init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, struct sigaction *sig_child, struct sigaction *sig_child_slash);

#endif