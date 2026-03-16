/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:34:00 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/16 12:01:22 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

void    parsing_heredoc(t_data *data);
void	here_doc(char *lim, int pipenb);
void	exec(char *cmd, char *envp[]);

#endif