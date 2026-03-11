/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 15:51:35 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

typedef struct s_gc
{
	void			*content;
	struct s_gc		*next;
	struct s_gc		*previous;
}					t_gc;

void	*ft_calloc_gc(size_t nmemb, size_t size, t_gc **gc);
int		ft_lstnew_gc(t_gc **gc);
void    ft_free_all_gc(t_gc **gc);
int		ft_lstadd_gc(t_gc **gc, void *content);


#endif