/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:04 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/28 15:05:15 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int     search_export(t_data *data, char *str, int *i, int *end)
{
    char    *temp;
    char    *temp2;
    int     j;
    
    j = 0;
    while (str[j] && data->env[*i][j] && data->env[*i][j] != '=')
        j++;
    temp = ft_substr(data->env[*i], 0, j);
    if (!temp)
        return (1);
    temp2 = ft_substr(str, 0, j);
    if (!temp2)
        return (free(temp), 1);
    if (strcmp(temp, temp2) == 0)
    {
        free(data->env[*i]);
        data->env[*i] = ft_strdup(str);
        *i += 1;
        return (free(temp2), free(temp), *end = 1, 1);
    }
    return (free(temp), free(temp2), *i += 1, 0);
}

int     fill_export(t_data *data, char *str, int end, int i)
{
    char    **cpy;
    
    while (data->env[i])
    {
        if (search_export(data, str, &i, &end))
            return (1);
        if (end == 1)
            return (0);
    }
    i = 0;
    cpy = ft_calloc(sizeof(char *), (ft_splitlen(data->env) + 2));
    if (!cpy)
        return (1);
    while (data->env[i])
    {
        cpy[i] = ft_strdup(data->env[i]);
        if (!cpy[i++])
            return (free_tab(cpy), 1);
	}
    cpy[i] = ft_strdup(str);
    if (!cpy[i])
        return (free_tab(cpy), 1);
    free_tab(data->env);
    data->env = cpy;
    return (0);
}

int    export(t_data *data, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!data->env)
        return (printf("env is cleared"), 1);
    if (!str)
    {
        while (data->env[i])
        	printf("declare -x %s\n", data->env[i++]);
        return (0);
    }
    while (str[i])
    {
        if (str[i++] == '=')
            j = 1;
    }
    if (j == 0)
        return (0);
    return (fill_export(data, str, 0, 0));
}
static int is_usable(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    if ((!ft_isalpha(str[0]) && str[0] != '_')
        || ft_strchr(str, '-'))
        return (printf("minishell: export: `%s': not a valid identifier\n", str), 0);
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '='
            && str[i] != ' ')
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
        return (export(data, NULL));
    while (*list && (*list)->type == BUILT_IN)
    {
        if (is_usable((*list)->content))
            return_value = return_value | export(data, (*list)->content);
        else
            return_value = 1;
        *list = (*list)->next;
    }
    return (return_value);
}


//export jsp=10 1yemp=54 prise prout@a=150 car=12