#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data, char **envp)
{
    if (!data->str[1])
        ft_error_gc("Error\nInvalid limiter\n", &data->gc);
    here_doc(data->str[1], 0, data);
    if (!signal_received)
        if (!data->str[2])
        {
            printf("alors la \n");
            exec("cat", envp);
        }
    return;
}