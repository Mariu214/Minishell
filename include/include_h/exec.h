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
void		exec(char *cmd, char *envp[]);
void        signal_handler(int signum);
void    	init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, struct sigaction *sig_child, struct sigaction *sig_child_slash);

#endif