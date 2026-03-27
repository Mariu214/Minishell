#include "../../include/minishell.h"

char    **export(char *envp[], char *str)
{
    int     i;
    char    **cpy;
    char    *temp;
    int     j;

    i = 0;
    if (!envp)
        return (printf("env is cleared"), NULL);
    if (!str)
    {
        while (envp[i])
        	printf("%s\n", envp[i++]);
        return (envp);
    }
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] && envp[i][j] != '=')
            j++;
        temp = ft_substr(envp[i], 0, j);
        if (temp)
        {
            if (strcmp(temp, str) == 0)
            {
                free(envp[i]);
                free(temp);
                envp[i] = ft_strdup(str);
                return (envp);
            }
            free(temp);
            i++;
        }
    }
    i = 0;
    cpy = ft_calloc(sizeof(char *), (ft_splitlen(envp) + 2));
    while (envp[i])
    {
        cpy[i] = ft_strdup(envp[i]);
        i++;
	}
    cpy[i] = ft_strdup(str);
    free_tab(envp);
    return (cpy);
}
