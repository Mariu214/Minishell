/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:54 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/08 13:36:11 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L

# include "../libft/include/libft.h"
# include "include_h/struct.h"
# include "include_h/exec.h"
# include "include_h/hardcoded.h"
# include "include_h/lexer.h"
# include "include_h/list.h"
# include "include_h/misc.h"
# include "include_h/parsing.h"
# include "include_h/pipe.h"
# include "include_h/redirection.h"
# include <dirent.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <limits.h>

extern t_data	*g_datacpy;

#endif
