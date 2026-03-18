#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data, char **envp)
{
    (void)envp;
    if (!data->str[1])
        ft_error_gc("Error\nInvalid limiter\n", &data->gc, 1);
    here_doc(data->str[1], 0, data);
    if (!data->str[2])
            exec("cat", envp);
    return;
}