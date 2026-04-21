/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/21 11:53:15 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int cd(t_data *data, char *str)
{
    char    *temp;
    int     return_value;
    
    if (chdir(str) == -1 )
    		return (printf("minishell: cd: %s: %s\n", str, strerror(errno)), 1);
    temp = getcwd(data->current_dir, 4096);
	if (!temp)
		return (perror("error :"), 1);
	temp = ft_strjoin("PWD=", temp);
	if (!temp)
		return (perror("error :"), 1);
	return_value = export(data, temp);
	free(temp);
    return (return_value);
}
    
int init_cd(t_data *data, t_lexst **list)
{
    char    *temp;
    int     return_value;
    
	*list = (*list)->next;
	if (!(*list) || (*list)->type != BUILT_IN)
    {
        temp = ft_getenv("HOME", data->env);
        if (!temp)
            return (perror("error :"), 1);
        return_value = cd(data, temp);
        free(temp);
        return (return_value);
    }
	if ((*list)->next && (*list)->next->type == BUILT_IN)
	{
		while (*list && (*list)->type == BUILT_IN)
			*list = (*list)->next;
		return (printf("minishell: cd: too many arguents\n"), 1);
	}
    return (cd(data, (*list)->content));
}
