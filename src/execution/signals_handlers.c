/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:21:32 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/24 11:30:08 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

void    child_quit(int signum)
{
    (void)signum;

    ft_shellerror_gc("", g_datacpy, 130, 0);
}

void    signal_quit(int signum)
{
    (void)signum;

    ft_shellerror_gc("", g_datacpy, 131, 0);
}

void    init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, struct sigaction *sig_child, struct sigaction *sig_child_slash)
{
        sig_child_slash->sa_handler = signal_quit;
	    sigemptyset(&sig_child_slash->sa_mask);
	    sig_child_slash->sa_flags = SA_RESTART;
        sig_child->sa_handler = child_quit;
	    sigemptyset(&sig_child->sa_mask);
	    sig_child->sa_flags = SA_RESTART;
        sig_int->sa_handler = signal_handler;
	    sigemptyset(&sig_int->sa_mask);
	    sig_int->sa_flags = SA_RESTART;
        sig_quit->sa_handler = SIG_IGN;
	    sigemptyset(&sig_quit->sa_mask);
	    sig_quit->sa_flags = SA_RESTART;
}

void    signal_handler(int signum)
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
