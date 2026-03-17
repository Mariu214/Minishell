#include "../../include/minishell.h"

void    init_parsing(t_data *data, char **envp)
{
    (void)envp;
    pid_t   child_line;
    int     i;

    i = 0;
    child_line = fork();
    if (!child_line)
    {
        while (data->str[i])
        {
            if (ft_strcmp(data->str[i], "<<") == 0)
                parsing_heredoc(data, envp);
            if (ft_strcmp(data->str[i], "cat") == 0)
                exec("cat", envp);
            i++;
        }
        exit (0);
    }
    else
    {
        int signal;

        waitpid(child_line, &signal, 0);
    }
    //printf("%i\n", dup(0));
    //exec(data->str[1], envp);
}

// void    init_parsing(t_data *data, char **envp)
// {
//     (void)envp;
//     (void)data;
//     pid_t   child_line;
//     int     i;

//     child_line = fork();
//     i = 0;
//     if (!child_line)
//     {
//         init_signal(&data->sig_int, &data->sig_quit, 0);
//         while (i++ < 5)
//             sleep(1);
//     }
//     else
//         wait(NULL);
//     //printf("%i\n", dup(0));
//     //exec(data->str[1], envp);
// }