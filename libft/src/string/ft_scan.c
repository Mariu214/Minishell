/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:35:43 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 14:23:59 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static	char	*read_line(char *line)
{
	char	*buffer;
	int		nb_read;

	nb_read = 1;
	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	while (nb_read > 0 && ft_strcmp(line, "\n") != 0)
	{
		nb_read = read(0, buffer, 1);
		if (nb_read == -1)
			return (free(buffer), free(line), NULL);
		buffer[1] = 0;
		line = renew(buffer, line);
		if (!line)
			return (NULL);
		if (ft_strcmp(buffer, "\n") == 0)
			break ;
	}
	return (free(buffer), line);
}

char	*ft_scan(char *prompt, int mode)
{
	char	*scaned;
	char	*line;

	ft_printf_fd(2, "%s", prompt);
	scaned = ft_calloc(1, 1);
	scaned = read_line(scaned);
	if (mode == 0)
		line = ft_substr(scaned, 0, ft_strlen(scaned) - 1);
	else
		line = ft_strdup(scaned);
	free(scaned);
	return (line);
}
