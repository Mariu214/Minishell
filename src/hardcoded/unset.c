/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:06:32 by malaimo           #+#    #+#             */
/*   Updated: 2026/04/30 10:58:09 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	del_variable(t_data *data, char *str, char *temp, int i)
{
	if (strcmp(temp, str) == 0)
	{
		free(data->env[i]);
		while (data->env[i + 1])
		{
			data->env[i] = data->env[i + 1];
			if (!data->env)
				return (1);
			i++;
		}
		data->env[i] = NULL;
		return (0);
	}
	return (0);
}

int	unset(t_data *data, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!data->env)
		return (printf("env is cleared"), 1);
	if (!str)
		return (printf("wrong argument"), 1);
	while (data->env[i])
	{
		temp = ft_substr(data->env[i], 0, ft_strlen(str));
		if (!temp)
			return (1);
		if (del_variable(data, str, temp, i))
			return (1);
		free(temp);
		i++;
	}
	return (0);
}

static int	is_usable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if ((!ft_isalpha(str[0]) && str[0] != '_') || ft_strchr(str, '-'))
		return (printf("minishell: unset: `%s': not a valid identifier\n", str),
			0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '=')
			return (printf("minishell: unset: `%s': not a valid identifier\n",
					str), 0);
		i++;
	}
	return (1);
}

int	init_unset(t_data *data, t_lexst **list)
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
			if (unset(data, (*list)->content))
				return (1);
		}
		else
			return_value = 1;
		*list = (*list)->next;
	}
	return (return_value);
}