/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:47:48 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 13:54:45 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <signal.h>

typedef struct s_sic
{
	pid_t			content;
	struct s_sic	*next;
	struct s_sic	*previous;
}					t_sic;

/* EXEC_SHELL */
void				exec(t_lexst **list, t_data *data);

/* HERE_DOC */
int					here_doc(char *lim, t_data *data);

/* SIGNALS_HANDLERS */
void				child_quit(int signum);
void				signal_quit(int signum);
void				signal_handler(int signum);
void				insig(struct sigaction *sig_it, struct sigaction *sig_qt);
void				inseg(struct sigaction *sig_chd, struct sigaction *sig_sh);

#endif