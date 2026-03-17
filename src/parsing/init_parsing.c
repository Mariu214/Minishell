#include "../../include/minishell.h"

void	init_parsing(t_data *data, char **envp)
{
	pid_t	child_line;
	int		i;

	i = 0;
	child_line = fork();
	if (!child_line)
	{
		maybe_pipe(data, envp);
		while (data->str[i])
		{
			if (ft_strcmp(data->str[i], "<<") == 0)
				parsing_heredoc(data, envp);
			if (ft_strcmp(data->str[i], "cat -e") == 0)
				exec("cat -e", envp);
			if (ft_strcmp(data->str[i], "cat") == 0)
				exec("cat", envp);
			if (ft_strcmp(data->str[i], "ls") == 0)
				exec("ls", envp);
			i++;
		}
		exit (0);
	}
	else
		wait(NULL);
}
