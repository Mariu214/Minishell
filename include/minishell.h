/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:54 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 14:45:51 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define _POSIX_C_SOURCE 200809L

# include "../libft/include/libft.h"
# include "include_h/pipe.h"
# include "include_h/redirection.h"
# include "include_h/misc.h"

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
#include <termios.h>

extern volatile int process_running;

typedef enum e_type
{
	CMD = 1,
	WORD,
	D_QUOTE,
	S_QUOTE,
	INPUT,
	OU_APPEND,
	OU_TRUNC,
	HEREDOC,
	PIPE,
	BUILT_IN,
}	t_type;

typedef enum e_quote
{
	WRD = 1,
	OPEN_D_QUOTE,
	CLOSED_D_QUOTE,
	OPEN_S_QUOTE,
	CLOSED_S_QUOTE,
}	t_quote;

# include "include_h/parsing.h"
# include "include_h/lexer.h"
# include "include_h/list.h"
# include "include_h/hardcoded.h"


typedef struct s_lexer
{
	int i;
	int j;
	int k;
	int	len;
	int	done;
	char *temp;
	char *temp2;
}		t_lexer;

typedef struct s_cmd
{
	char	*str;
	int		is_cmd;
	int		is_file;
	int		is_redirection;
	int		is_pipe;
}			t_cmd;

typedef struct s_data
{
	t_gc	*gc;
	t_cmd	*line;
	char	*str;
	char	**env;
	struct sigaction	sig_int;
	struct sigaction	sig_quit;
	struct sigaction	sig_child;
	struct sigaction	sig_child_slash;
	int		pipenb;
	int		dollar;
	int		pipedone;
	char	current_dir[4096];
	t_lexst	*list;
}			t_data;

# include "include_h/exec.h"

typedef struct s_command
{
	char	**s_cmd;
	int		free;
}			t_command;

typedef struct s_accessible
{
	char	**all_path;
	char	**s_cmd;
	char	*join;
	char	*path;
	int		i;
}			t_accessible;

#endif
