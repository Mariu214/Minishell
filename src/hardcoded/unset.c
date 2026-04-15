/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:06:32 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/15 15:30:52 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int is_usable(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    if (!ft_isdigit(str[0] && str[0] != '_')
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

int init_unset(t_data *data, t_lexst **list)
{
    int return_value;

    return_value = 0;
    *list = (*list)->next;
    if (!(*list) || (*list)->type != BUILT_IN)
        return (0);
    while (*list && (*list)->type == BUILT_IN)
    {
        if (is_usable((*list)->content))
        {
            data->env = unset(data->env, (*list)->content);
            if (!data->env)
                return (-1);
        }
        else 
            return_value = 1;
        *list = (*list)->next;
    }
    return (return_value);
}