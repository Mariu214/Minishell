/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:16:41 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/17 16:48:33 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    t_gc    *gc;
    char    *tab;
    char    *tab2;
    char    *tab3;
    // char    *str

    gc = NULL;
    tab = ft_calloc_gc(ft_strlen("abcde"), sizeof(char), &gc);
    tab = "abcde";
    tab2 = ft_strdup_gc(tab, &gc);
    tab3 = ft_strjoin_gc(tab, tab2, &gc);
    printf("%d\n", ft_delone_gc(&gc, tab3));
    ft_free_all_gc(&gc);
}