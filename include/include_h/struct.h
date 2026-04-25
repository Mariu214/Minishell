#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_lexst
{
	char			*content;
	t_type			type;
	t_quote			word_type;
	struct s_lexst	*next;
	struct s_lexst	*previous;
}					t_lexst;

typedef struct s_cmd
{
	char	*str;
	int		is_cmd;
	int		is_file;
	int		is_redirection;
	int		is_pipe;
}			t_cmd;

typedef struct e_token
{
	t_type			type;
	t_quote			quote;
}					t_token;

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
	int		old_stdin;
	int		old_stdout;
	int		process;
}			t_data;

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