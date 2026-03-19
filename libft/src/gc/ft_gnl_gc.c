/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_gc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:37:19 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 12:22:40 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif

static char	*line(char *buffer, t_gc **gc)
{
	char	*retu;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	retu = ft_calloc_gc(sizeof(char), i + 2, gc);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		retu[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		retu[i++] = '\n';
	return (retu[i] = '\0', retu);
}

static char	*next_line(char	*buffer, t_gc **gc)
{
	char	*retu;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_delone_gc(buffer, gc), NULL);
	retu = ft_calloc_gc(sizeof(char), ft_strlen(buffer) - i + 1, gc);
	if (!retu)
		return (ft_delone_gc(buffer, gc), NULL);
	i++;
	while (buffer[i])
		retu[j++] = buffer[i++];
	return (retu[j] = '\0', ft_delone_gc(buffer, gc), retu);
}

static char	*read_file(char *retu, int fd, t_gc **gc)
{
	char	*buffer;
	int		nb_read;

	nb_read = 1;
	if (!retu)
		retu = ft_calloc_gc(1, 1, gc);
	buffer = ft_calloc_gc(sizeof(char), BUFFER_SIZE + 1, gc);
	if (!buffer)
		return (NULL);
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (ft_delone_gc(buffer, gc), ft_delone_gc(retu, gc), NULL);
		buffer[nb_read] = '\0';
		retu = ft_renew_gc(retu, buffer, gc);
		if (!retu)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (retu);
}

char	*ft_gnl_gc(int fd, t_gc **gc)
{
	static char	*buffer[1024];
	char		*retu;

	if ((fd < 0 && BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
		return (ft_delone_gc(buffer[fd], gc), buffer[fd] = NULL, NULL);
	buffer[fd] = read_file(buffer[fd], fd, gc);
	if (!buffer[fd])
		return (ft_delone_gc(buffer[fd], gc), buffer[fd] = NULL, NULL);
	retu = line(buffer[fd], gc);
	if (!retu)
		return (ft_delone_gc(buffer[fd], gc), buffer[fd] = NULL, NULL);
	buffer[fd] = next_line(buffer[fd], gc);
	if (!buffer[fd])
		return (ft_delone_gc(buffer[fd], gc), buffer[fd] = NULL, retu);
	return (retu);
}
