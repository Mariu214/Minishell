/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:04 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 15:30:44 by malaimo          ###   ########.fr       */
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

static int is_usable(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    if (!ft_isdigit(str[0]) && str[0] != '_' && str[0] != '='
        || ft_strchr(str, '-'))
        return (printf("minishell: export: `%s': not a valid identifier", str), 0);
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (printf("minishell: export: `%s': not a valid identifier", str), 0);
        i++;
    }
    return (1);
}

int init_export(t_data *data, t_lexst **list)
{
    int return_value;

    return_value = 0;
    *list = (*list)->next;
    if (!(*list) || (*list)->type != BUILT_IN)
    {
        data->env = export(data->env, NULL);
        if (!data->env)
                return (1);
    }
    while (*list && (*list)->type == BUILT_IN)
    {
        if (is_usable((*list)->content))
        {
            data->env = export(data->env, (*list)->content);
            if (!data->env)
                return (-1);
        }
        else
            return_value = 1;
        *list = (*list)->next;
    }
    return (return_value);
}
