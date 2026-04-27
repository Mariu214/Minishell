/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:35:43 by jdelmott          #+#    #+#             */
/*   Updated: 2026/04/24 14:50:00 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#define RM_NL 0
#define NL 

static char *read_line(char *line, int fd)
{
    char    *buffer;
    int     nb_read;

    nb_read = 1;
    buffer = ft_calloc(sizeof(char), 2);
    if (!buffer)
        return (NULL);
    while (nb_read > 0 && ft_strcmp(line, "\n") != 0)
    {
        nb_read = read(fd, buffer, 1);
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

char    *ft_scan_gc(char *prompt, int mode, t_gc **gc, int fd)
{
    char  *scaned;
    char  *line;
  
    ft_printf_fd(2, "%s", prompt);
    scaned = ft_calloc(1, 1);
    scaned = read_line(scaned, fd);
    if (!scaned)
        return (NULL);
    if (mode == 0)// remove the '\n'
        line = ft_substr_gc(scaned, 0, ft_strlen(scaned) - 1, gc);
    else// leave the '\n'
        line = ft_strdup_gc(scaned, gc);
    free(scaned);
    return (line);
}
