/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:24:07 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 10:58:34 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int     lexing_sort(t_data *data, int *i, int jsp, t_lexst **list)
// {
//     if (data->str[*i] == '"')
//     {
//         if (lexing_d_quote(data, i, WORD, list))
//             return (1);
//     }
//     else if (data->str[*i] == '\'')
//     {
//         if (lexing_s_quote(data, i, WORD, list))
//             return (1);
//     }
//     else if (jsp == 0)
//     {
//         if (lexing_word(data, i, list))
//             return (1);
//     }
//     else if (jsp >= 1)
//     {
//         if (lexing_cmd(data, i, list))
//             return (1);
//     }
//     return (0);
// }

int	lexing_precise_redirection(t_data *data, char *str, t_lexst **list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i + 1] && str[i] == '<' && str[i + 1] == '<')
		{
			if (ft_add_node(list, ft_substr_gc(str, i, 2, &data->gc),
					define_type(HEREDOC, WRD), &data->gc))
				return (1);
			i += 2;
		}
		else if ((str[i] && str[i + 1] && str[i] == '>' && str[i + 1] == '>'))
		{
			if (ft_add_node(list, ft_substr_gc(str, i, 2, &data->gc),
					define_type(OU_APPEND, WRD), &data->gc))
				return (1);
			i += 2;
		}
		else if (str[i] && str[i] == '<')
		{
			if (ft_add_node(list, ft_substr_gc(str, i, 1, &data->gc),
					define_type(INPUT, WRD), &data->gc))
				return (1);
			i++;
		}
		else if (str[i] && str[i] == '>')
		{
			if (ft_add_node(list, ft_substr_gc(str, i, 1, &data->gc),
					define_type(OU_TRUNC, WRD), &data->gc))
				return (1);
			i++;
		}
	}
	return (0);
}

int	lexing_redirection(t_data *data, int *i, t_lexst **list)
{
	int		j;
	char	*temp;

	j = *i;
	while (data->str[j] && (data->str[j] == '<' || data->str[j] == '>'))
		j++;
	temp = ft_substr(data->str, *i, j - *i);
	if (!temp)
		return (1);
	if (lexing_precise_redirection(data, temp, list))
		return (free(temp), 1);
	if (data->str[j] && data->str[j] == ' ')
		j++;
	*i = j;
	return (free(temp), 0);
}
