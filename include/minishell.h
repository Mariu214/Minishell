/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:54 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/16 12:03:19 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define _POSIX_C_SOURCE 200809L

# include "../libft/include/libft.h"
# include "include_h/parsing.h"
# include "include_h/exec.h"

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_data
{
	t_gc	*gc;
	char	**str;
}			t_data;

typedef struct s_command
{
	char	**s_cmd;
	int		free;
}			t_command;

typedef struct s_accessible
{
	char	**all_path;
	char	**s_cmd;
	char	*join;
	char	*path;
	int		i;
}			t_accessible;

#endif