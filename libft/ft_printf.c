/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:01:41 by jdelmott          #+#    #+#             */
/*   Updated: 2025/12/15 14:03:33 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif(const char *str, va_list *lst, int *i)
{
	*i += 1;
	if (*(str + 1) == 'c')
		return (ft_putchar(va_arg(*lst, int)));
	else if (*(str + 1) == 's')
		return (ft_putstr(va_arg(*lst, char *)));
	else if (*(str + 1) == 'p')
		return (ft_putnbr_p(va_arg(*lst, unsigned long)));
	else if (*(str + 1) == 'x')
		return (ft_putnbr_base(va_arg(*lst, unsigned int), "0123456789abcdef"));
	else if (*(str + 1) == 'i' || *(str + 1) == 'd')
		return (ft_putnbr(va_arg(*lst, int)));
	else if (*(str + 1) == 'u')
		return (ft_putnbr_u(va_arg(*lst, int)));
	else if (*(str + 1) == 'X')
		return (ft_putnbr_base(va_arg(*lst, unsigned int), "0123456789ABCDEF"));
	else if (*(str + 1) == '%')
		return (ft_putchar('%'));
	else if (*(str + 1))
		return (ft_putchar(*str) + ft_putchar(*(str + 1)));
	else
		*i -= 1;
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;
	int		temp;

	temp = 0;
	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
			temp = verif(str + i, &lst, &i);
		else
			temp = ft_putchar(str[i]);
		if (temp >= 0)
			len += temp;
		else
			len = temp;
		i++;
	}
	va_end(lst);
	return (len);
}
