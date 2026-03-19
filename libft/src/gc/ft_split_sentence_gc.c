/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sentence_gc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:29:45 by jdelmott          #+#    #+#             */
/*   Updated: 2026/03/19 12:29:47 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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

static char	**do_split(t_split_sentence *data, const char *str, char *start,
		t_gc **gc)
{
	int	words;
	int	i;
	int	j;

	i = 0;
	words = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == data->sep && str[i])
			i++;
		j = get_words(&str[i], data->sep, start);
		data->split[words] = ft_calloc_gc(sizeof(char), j + 1, gc);
		if (!data->split[words])
			return (0);
		ft_strlcpy(data->split[words], (char *)&str[i], j + 1);
		i += j;
		words++;
		if (words == count_words(str, data->sep, start))
			break ;
	}
	data->split[words] = NULL;
	return (data->split);
}

char	**ft_split_sentence_gc(char *str, const char separateur, char *start,
		t_gc **gc)
{
	int					words;
	t_split_sentence	data;

	if (!str)
		return (NULL);
	data.sep = separateur;
	words = count_words(str, data.sep, start);
	data.split = ft_calloc_gc(sizeof(char *), words + 1, gc);
	if (data.split == NULL)
		return (0);
	if (!str[0] || words == 0)
		return (data.split);
	data.split = do_split(&data, str, start, gc);
	if (!data.split)
		return (NULL);
	return (data.split);
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
