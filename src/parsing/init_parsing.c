#include "../../include/minishell.h"

void    init_parsing(t_data *data, char **envp)
{
    (void)envp;
    pid_t   child_line;
    int     i;

    i = 0;
    child_line = fork();
    count_pipe(data);// executer pipe_handler en fonction de pipe
    if (!child_line)
    {
        pipe_handler(data->str[i], envp);
        while (data->str[i])
        {
            if (ft_strcmp(data->str[i], "<<") == 0)
                parsing_heredoc(data);
            if (ft_strcmp(data->str[i], "cat") == 0)
                exec("cat", envp);
            i++;
        }
        exit (0);
    }
    else
        wait(NULL);
}
