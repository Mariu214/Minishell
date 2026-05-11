/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:41:06 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/11 20:08:57 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	parsing_last_pipe_next(t_data *data, t_lexst **temp, char **tmp)
{
	while (!data->str[0])
	{
		ft_delone_gc(data->str, &data->gc);
		print_pipe(countpipe(data) - 1);
		data->str = ft_scan_gc("pipe> ", 0, &data->gc, 0);
		if (!data->str)
			ft_shellerror_gc("error: malloc\n", data, 0, 0);
	}
	if (!data->str)
		return (ft_shellerror_gc("last_pipe\n", data, 0, 1));
	init_lexer(data, temp);
	ft_add_node_list(&data->list, temp);
	if (parsing_pipe(data, (*temp)))
		return (data->str = ft_renew_gc((*tmp), data->str, 2, &data->gc), 1);
	data->str = ft_renew_gc((*tmp), data->str, 2, &data->gc);
	if (!data->str)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	return (0);
}

int	parsing_last_pipe(t_data *data)
{
	t_lexst	*temp;
	char	*tmp;

	temp = NULL;
	tmp = ft_strdup_gc(data->str, &data->gc);
	if (!tmp)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	tmp = ft_renew_gc(tmp, " ", 0, &data->gc);
	if (!tmp)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	ft_delone_gc(data->str, &data->gc);
	data->str = ft_strdup_gc(NULL, &data->gc);
	if (!data->str)
		ft_shellerror_gc("error: malloc\n", data, 0, 0);
	if (parsing_last_pipe_next(data, &temp, &tmp))
		return (1);
	return (0);
}

int	is_last_pipe(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i && (line[i] == ' ' || line[i] == '|'))
	{
		if (line[i] == '|')
			return (1);
		i--;
	}
	return (0);
}
