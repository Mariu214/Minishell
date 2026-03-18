/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/18 13:20:58 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

typedef struct s_gc
{
	void		*content;
	struct s_gc	*next;
	struct s_gc	*previous;
}				t_gc;

typedef struct s_split_space
{
	char		**split;
	char		sep;
}				t_split_space;

void			*ft_calloc_gc(size_t nmemb, size_t size, t_gc **gc);
void			ft_free_all_gc(t_gc **gc);
int				ft_lstadd_gc(t_gc **gc, void *content);
char			*ft_strdup_gc(const char *s, t_gc **gc);
char			*ft_strjoin_gc(char const *s1, char const *s2, t_gc **gc);
char			*ft_renew_gc(char *start, char *end, t_gc **gc);
char			**ft_split_gc(const char *str, char sep, t_gc **gc);
char			**ft_split_space_gc(char *str, const char separateur,
					char *start, t_gc **gc);
void			ft_error_gc(char *str, t_gc **gc, int out);
int				ft_delone_gc(void *target, t_gc **gc);

#endif