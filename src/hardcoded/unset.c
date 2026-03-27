#include "../../include/minishell.h"

char    **unset(char *envp[], char *str)
{
    int i;
    int j;
    char    *temp;

    i = 0;
    if (!envp)
        return (printf("env is cleared"), NULL);
    if (!str)
        return (printf("wrong argument"), NULL);
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
                free(temp);
                free(envp[i]);
                while (envp[i + 1])
                {
                    envp[i]= envp[i + 1];
                    i++;
                }
                envp[i] = NULL;
                return (envp);
            }
            free(temp);
        }
        i++;
    }
    return (envp);
}