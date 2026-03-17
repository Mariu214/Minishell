# include "../../include/minishell.h"


void    child_quit(int signum)
{
    (void)signum;
    if (kill(getpid(), SIGINT) <= 0)
        exit(1);
    rl_on_new_line();
    rl_redisplay();
    signal_received = 1;
}

void    init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, int i)
{
    if (i == 0)
    {
        sig_int->sa_handler = signal_handler;
	    sigemptyset(&sig_int->sa_mask);
	    sig_int->sa_flags = SA_RESTART;
        sig_quit->sa_handler = SIG_IGN;
	    sigemptyset(&sig_quit->sa_mask);
	    sig_quit->sa_flags = SA_RESTART;
    }
    // else
    // {
    //     sig_int->sa_handler = child_quit;
	//     sigemptyset(&sig_int->sa_mask);
	//     sig_int->sa_flags = 0;
    //     sig_quit->sa_handler = child_quit;
	//     sigemptyset(&sig_quit->sa_mask);
	//     sig_quit->sa_flags = 0;
    // }
}

void    signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        rl_on_new_line();
        rl_redisplay();
        signal_received = 1;
    }
}
