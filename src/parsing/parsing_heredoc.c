#include "../../include/minishell.h"

void    parsing_heredoc(t_data *data)
{
    if (!data->str[1])
        ft_error_gc("Error\nInvalid limiter\n", &data->gc);
    here_doc(data->str[1], 0);
    return;
}