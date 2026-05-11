/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:51:40 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/21 10:25:57 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_getenv_gc(const char *name, char **env, t_gc **gc)
{
	int		i;
	int		j;
	char	*temp;
	char	*str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		temp = ft_substr(env[i], 0, j);
		if (temp)
		{
			if (ft_strcmp(temp, name) == 0)
			{
				str = ft_substr_gc(env[i], j + 1, ft_strlen(env[i]), gc);
				if (str)
					return (free(temp), str);
			}
			free(temp);
		}
		i++;
	}
	return (NULL);
}
