/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:44:56 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/21 14:32:09 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		is_built_in(const char *str)
{
	if (ft_strcmp(str, "export") == 0 || ft_strcmp(str, "unset") == 0 
            || ft_strcmp(str, "$?") == 0 || ft_strcmp(str, "echo") == 0
            || ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "env") == 0
            || ft_strcmp(str, "pwd") == 0)
		return (1);
	else 
		return (0);
}

void	lexing_built_in(t_lexst **list)
{
    t_lexst *temp;

    temp = *list;
    while (temp)
    {
        if (temp->type == CMD && is_built_in(temp->content))
        {
            while (temp && temp->type == CMD)
            {
                temp->type = BUILT_IN;
                temp = temp->next;
            }
        }
		if (temp)
        	temp = temp->next;
    }
}


int		lexing_cmd(t_data *data, int *i, t_lexst **list)
{
	int     j;
    char    *temp;
    
    j = *i;
	while (data->str[j] && data->str[j] != '>' && data->str[j] != '<'
			&& data->str[j] != '|' && data->str[j] != '\'' && data->str[j] != '"' && data->str[j] != ' ')// pas encor sur et certain du ' '
        j++;
	temp = ft_substr_gc(data->str, *i, j - *i, &data->gc);
    if (!temp)
        return (1);
    ft_add_node(list, temp, define_type(CMD, WRD), &data->gc);
	if (data->str[j] && data->str[j] == ' ')
		j++;
	*i = j;
	// while (data->str[*i] && data->str[*i] != '>' && data->str[*i] != '<'
	// 		&& data->str[*i] != '|')
	// {
	// 	if (lexing_word(data, i))
	// 		return (1);
    //     if (data->str[*i] && data->str[*i] == ' ')
	// 	    *i += 1;
	// }
    return (0);
}