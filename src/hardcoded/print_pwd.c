/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:19:24 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/11 20:13:49 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_pwd(t_data *data, t_lexst **list)
{
	char	*temp;

	*list = (*list)->next;
	if (!getcwd(data->current_dir, 4096))
	{
		temp = ft_getenv_gc("OLDPWD", data->env, &data->gc);
		if (!temp)
		{
			temp = ft_getenv_gc("PWD", data->env, &data->gc);
			if (!temp)
			{
				printf("Minishell: error: can't access current directory");
				return (1);
			}
		}
		printf("%s\n", temp);
	}
	else
		printf("%s\n", data->current_dir);
	return (0);
}
