/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:21:32 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/06 14:26:33 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_quit(int signum)
{
	(void)signum;
	ft_shellerror_gc("", g_datacpy, 130, 0);
}

void	signal_quit(int signum)
{
	(void)signum;
	ft_shellerror_gc("", g_datacpy, 131, 0);
}

void	insig(struct sigaction *sig_it, struct sigaction *sig_qt)
{
	sig_it->sa_handler = signal_handler;
	sigemptyset(&sig_it->sa_mask);
	sig_it->sa_flags = SA_RESTART;
	sig_qt->sa_handler = SIG_IGN;
	sigemptyset(&sig_qt->sa_mask);
	sig_qt->sa_flags = SA_RESTART;
}

void	inseg(struct sigaction *sig_chd, struct sigaction *sig_sh)
{
	sig_sh->sa_handler = signal_quit;
	sigemptyset(&sig_sh->sa_mask);
	sig_sh->sa_flags = SA_RESTART;
	sig_chd->sa_handler = child_quit;
	sigemptyset(&sig_chd->sa_mask);
	sig_chd->sa_flags = SA_RESTART;
}

void	signal_handler(int signum)
{
	(void)signum;
	if (!g_datacpy->process)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		write(1, "\n", 1);
}
