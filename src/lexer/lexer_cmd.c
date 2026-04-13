/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:44:56 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/13 14:12:27 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	lexing_built_in(t_data *data)
{
    t_lexst *temp;

    temp = data->list;
    while (temp)
    {
        if (temp->type == CMD && (ft_strcmp(temp->content, "export") == 0 || ft_strcmp(temp->content, "unset") == 0 
            || ft_strcmp(temp->content, "exit") == 0 || ft_strcmp(temp->content, "echo") == 0
            || ft_strcmp(temp->content, "cd") == 0 || ft_strcmp(temp->content, "env") == 0
            || ft_strcmp(temp->content, "pwd") == 0 ))
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


int		lexing_cmd(t_data *data, int *i)
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
    ft_add_node(&data->list, temp, define_type(CMD, WRD), &data->gc);
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