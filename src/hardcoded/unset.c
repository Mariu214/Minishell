#include "../../include/minishell.h"

char    **unset(char *envp[], char *str)
{
    int i;
    char    *temp;

    i = 0;
    if (!envp)
        return (printf("env is cleared"), NULL);
    if (!str)
        return (printf("wrong argument"), NULL);
    while (envp[i])
    {
        temp = ft_substr(envp[i], 0, ft_strlen(str));
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

int init_unset(t_data *data, int i)
{
    char    **temp;
    int     j;

    temp = ft_split(data->line[i].str, ' ');
    j = 1;
    if (!temp[j])
    {
        free(temp);
        return (0);
    }
    while(temp[j])
    {
        data->env = unset(data->env, temp[j++]);
        if (!data->env)
        {
            free(temp);
            return (-1);
        }
    }
    free(temp);
    return (0);
}