/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:51:40 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/09 14:55:46 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_getenv(const char *name, char **env)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		temp = ft_substr(env[i], 0, j);
		if (ft_strcmp(temp, name) == 0)
		{
			free(temp);
			return (env[i] + j + 1);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

/*int     main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	ft_printf("%s\n", ft_getenv("TERM_PROGRAM", env));
}
*/