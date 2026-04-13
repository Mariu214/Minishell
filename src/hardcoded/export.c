/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:04 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/13 17:10:05 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char    **export(char *envp[], char *str)
{
    int     i;
    char    **cpy;
    char    *temp;
    char    *temp2;
    int     j;

    i = 0;
    j = 0;
    if (!envp)
        return (printf("env is cleared"), NULL);
    if (!str)
    {
        while (envp[i])
        	printf("declare -x %s\n", envp[i++]);
        return (envp);
    }
    while (str[i])
    {
        if (str[i++] == '=')
            j = 1;
    }
    if (j == 0)
        return (envp);
    i = 0;
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] && envp[i][j] != '=')
            j++;
        temp = ft_substr(envp[i], 0, j);
        j = 0;
        while (str[j] && str[j] != '=')
            j++;
        temp2 = ft_substr(str, 0, j);
        if (temp && temp2)
        {
            if (strcmp(temp, temp2) == 0)
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

int init_export(t_data *data, int i)
{
    char    **temp;
    int     j;

    temp = ft_split(data->line[i].str, ' ');
    j = 1;
    if (!temp[j])
    {
        export(data->env, NULL);
        free(temp);
        return (0);
    }
    while(temp[j])
    {
        data->env = export(data->env, temp[j++]);
        if (!data->env)
        {
            free(temp);
            return (-1);
        }
    }
    free(temp);
    return (0);
}

