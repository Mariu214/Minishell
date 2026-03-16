#include "../../include/minishell.h"

void    init_parsing(t_data *data, char **envp)
{

    (void)envp;
    if (ft_strcmp(data->str[0], "here_doc") == 0)
        parsing_heredoc(data);
    // exec(data->str[1], envp);
}