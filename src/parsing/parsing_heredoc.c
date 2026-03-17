#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data, char **envp)
{
    if (!data->str[1])
        ft_error_gc("Error\nInvalid limiter\n", &data->gc);
    here_doc(data->str[1], 0);
    if (!data->str[2])
        exec("cat", envp);
    return;
}