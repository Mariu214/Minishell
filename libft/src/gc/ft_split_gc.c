/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:53:48 by malaimo           #+#    #+#             */
/*   Updated: 2026/03/11 14:53:49 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	**do_split(char **split, const char *str, char c, t_gc **gc)
{
	int	words;
	int	i;
	int	j;

	i = 0;
	words = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i + j] != c && str[i + j])
			j++;
		split[words] = ft_calloc_gc(sizeof(char), j + 1, gc);
		if (!split[words])
			return (0);
		ft_strlcpy(split[words], (char *)&str[i], j + 1);
		i += j;
		words++;
		if (words == count_words(str, c))
			break ;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split_gc(const char *str, char sep, t_gc **gc)
{
	char	**split;
	int		words;

	words = count_words(str, sep);
	split = ft_calloc_gc(sizeof(char *), words + 1, gc);
	if (split == NULL)
		return (NULL);
	if (!str[0] || words == 0)
		return (split);
	split = do_split(split, str, sep, gc);
	if (!split)
		return (NULL);
	return (split);
}

/*
int	main(int argc, char *argv[])
{
	(void)argc;
	int i = 0;
	char    **split;
	printf("%i\n", count_words(argv[1], ' '));
	split = ft_split(argv[1], ' ');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}*/
