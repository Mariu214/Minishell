/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:27:07 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/06 09:46:03 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_file(char *fd_arg, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(fd_arg, O_RDONLY, 0777);
	else if (mode == 1)
		fd = open(fd_arg, O_CREAT | O_WRONLY | O_APPEND, 0777);
	else
		fd = open(fd_arg, O_CREAT | O_WRONLY | O_TRUNC, 0777);
			// si je retire trunc ca marche mais ca fait pas ce qui fqut donc en vrai je sais pas trop
	if (fd == -1)
	{
		ft_printf_fd(2, "minishell: %s: %s\n", fd_arg, strerror(errno));
		if (mode == 0)
			return (-1);
		return (-2);
	}
	return (fd);
}
