/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:58:33 by jdelmott          #+#    #+#             */
/*   Updated: 2026/01/28 14:32:32 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr_back(const char *big, const char *little, size_t n)
{
	const unsigned char	*b;
	const unsigned char	*l;
	size_t				i;
	size_t				j;

	b = (const unsigned char *)big;
	l = (const unsigned char *)little;
	i = ft_strlen(big);
	j = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while (n > 0)
	{
		while (big[i] == little[j] && j >= 0 && i >= 0)
		{
			i--;
			j--;
		}
		if (big[i + 1] == little[0])
			return ((char *)(big + i + 1));
		else
			break ;
	}
	return (NULL);
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", ft_strnstr_back(argv[1], ".ber", 4));
}*/
