/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:08:58 by jdelmott          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:20 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloctrim(char *new, char *s1, int start, int end)
{
	int	j;

	j = 0;
	new = malloc(sizeof(char) * ((end - start) + 2));
	if (!new)
		return (NULL);
	while (start + j <= end)
	{
		new[j] = s1[start + j];
		j++;
	}
	new[j] = '\0';
	if (!new)
		return (NULL);
	while (start + j <= end)
	{
		new[j] = s1[start + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		j;
	int		start;
	int		end;

	new = NULL;
	j = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	if ((end - start) < 0)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = malloctrim(new, (char *)s1, start, end);
	return (new);
}
