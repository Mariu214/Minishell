#ifndef EXEC_H
# define EXEC_H

# include <signal.h>

void		here_doc(char *lim, int pipenb);
void		exec(char *cmd, char *envp[]);
void        signal_handler(int signum);
void    init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, int i);

#endif