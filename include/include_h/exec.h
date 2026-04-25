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
void	exec(t_lexst **list, t_data *data);

/* HERE_DOC */
int		here_doc(char *lim, t_data *data);

/* SIGNALS_HANDLERS */
void    	child_quit(int signum);
void    	signal_quit(int signum);
void        signal_handler(int signum);
void    	init_signal(struct sigaction *sig_int, struct sigaction *sig_quit, struct sigaction *sig_child, struct sigaction *sig_child_slash);

#endif