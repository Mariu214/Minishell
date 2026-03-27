/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:07 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/26 10:17:20 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_file(char *fd_arg, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(fd_arg, O_RDONLY, 0777);
	else if (mode == 1)
		fd = open(fd_arg, O_CREAT | O_RDWR | O_APPEND, 0777);
	else
		fd = open(fd_arg, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_printf_fd(2, "minishell: %s: %s\n", fd_arg, strerror(errno));
		if (mode == 0)
			exit(126);
		exit(1);
	}
	return (fd);
}
