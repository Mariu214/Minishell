/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:04 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/16 10:05:48 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int replace_env(t_data *data, char *str, int i)
{
    int     j;
    char    *temp;
    char    *temp2;
    
    j = 0;
    while (data->env[i][j] && data->env[i][j] != '=')
        j++;
    temp = ft_substr(data->env[i], 0, j);
    j = 0;
    while (str[j] && str[j] != '=')
        j++;
    temp2 = ft_substr(str, 0, j);
    if (temp && temp2)
    {
        if (strcmp(temp, temp2) == 0)
        {
            free(data->env[i]);
            free(temp);
            free(temp2);
            data->env[i] = ft_strdup(str);
            return (0);
        }
        free(temp);
        free(temp2);
        i++;
    }
    return (0);
}

int fill_env(t_data *data, char *str, int i)
{
    int i;
    int return_value;
    
    i = 0;
    while (data->env[i])
    {
        return_value = replace_env(data, str, i);
        if (return_value)
            return (return_value);
        i++;
    }
    i = 0;
    if (ft_delsplit_gc(data->export, &data->gc))
        return (1);
    data->export = ft_calloc_gc(sizeof(char *), (ft_splitlen(data->env) + 2), &data->gc);
    while (data->env[i])
        data->export[i] = ft_strdup_gc(data->env[i++], &data->gc);
    data->export[i] = ft_strdup_gc(str, &data->gc);
    free_tab(data->env);
    data->env = ft_splitdup_gc(data->export, &data->gc);
    return (0);
}

int export(t_data *data, char *str)
{
    int     i;
    int     j;
    int     return_value;

    i = 0;
    j = 0;
    if (!data->env)
        return (printf("env is cleared"), 1);
    if (!str)
    {
        while (data->env[i])
        	printf("declare -x %s\n", data->export[i++]);
        return (0);
    }
    while (str[i])
    {
        if (str[i++] == '=')
        {
            fill_env(data)
        }
    }
    if (j == 0)
    {
        data->export = ft_calloc_gc(sizeof(char *), (ft_splitlen(data->env) + 2), &data->gc);
        while (data->env[i])
            data->export[i] = ft_strdup_gc(data->env[i++], &data->gc);
        data->export[i] = ft_strdup_gc(str, &data->gc);
        return (0);
    }
}

static int is_usable(char *str)
{
    int i;
    
    i = 0;
    printf("str = %s\n", str);
    if (!str)
        return (0);
    if ((!ft_isalpha(str[0]) && str[0] != '_')
        || ft_strchr(str, '-'))
        return (printf("minishell: export: `%s': not a valid identifier\n", str), 0);
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '=')
            return (printf("minishell: export: `%s': not a valid identifier\n", str), 0);
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
