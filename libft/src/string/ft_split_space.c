/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:03:36 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/10 10:12:20 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	free_split(char **split, int count)
{
	while (count--)
		free(split[count]);
	free(split);
	exit(1);
}

static int	count_words(const char *str, char c, char *start)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str[0] || !str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
		{
			if (is_there(str[i], start))
			{
				i++;
				while (!is_there(str[i], start))
					i++;
			}
			i++;
		}
	}
	return (count);
}

static int	get_words(const char *str, char c, char *start)
{
	int	j;

	j = 0;
	while (str[j] != c && str[j])
	{
		if (is_there(str[j], start))
		{
			j++;
			while (!is_there(str[j], start))
				j++;
		}
		j++;
	}
	return (j);
}

static char	**do_split(char **split, const char *str, char c, char *start)
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
		j = get_words(&str[i], c, start);
		split[words] = ft_calloc(sizeof(char), j + 1);
		if (!split[words])
			free_split(split, words);
		ft_strlcpy(split[words], (char *)&str[i], j + 1);
		i += j;
		words++;
		if (words == count_words(str, c, start))
			break ;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split_space(char *str, const char sep, char *start)
{
	char	**split;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, sep, start);
	split = ft_calloc(sizeof(char *), words + 1);
	if (split == NULL)
		return (0);
	if (!str[0] || words == 0)
		return (split);
	return (do_split(split, str, sep, start));
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	int i = 0;
	char **split;

	printf("words = %i\n", count_words(argv[1], argv[2][0], argv[3]));
	split = split_pipex(argv[1], argv[2][0], argv[3]);
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