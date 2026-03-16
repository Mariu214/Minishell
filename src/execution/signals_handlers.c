# include "../../include/minishell.h"

void    init_signal(struct sigaction *sig_int, struct sigaction *sig_quit)
{
    sig_int->sa_handler = signal_handler;
	sigemptyset(&sig_int->sa_mask);
	sig_int->sa_flags = SA_RESTART;
    sig_quit->sa_handler = SIG_IGN;
	sigemptyset(&sig_quit->sa_mask);
	sig_quit->sa_flags = SA_RESTART;
}

void    signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        write(1, "\n", 1);  
        rl_on_new_line();
        rl_redisplay();
        signal_received = 1;
    }
    if (signum == SIGQUIT)
    {

    }
}
