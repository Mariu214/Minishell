#include "minishell.h"

int main(void)
{
    char    *line;
    t_gc    *gc;
    char    **args;
    int     i;

    gc = NULL;
    i = 0;
    line = readline(">minishell ");
    if (!line)
        ft_free_all_gc(&gc);
    printf("%s\n", line);
    args = ft_split_gc(line, ' ', &gc);
    if (!args)
        ft_free_all_gc(&gc);
    while (args[i])
        printf("%s\n", args[i++]);
    ft_free_all_gc(&gc);
    return (0);
}