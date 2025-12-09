/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:16:04 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/04 15:59:21 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

size_t	ft_putptr(void *p)
{
	size_t			count;
	unsigned long	tmp;

	tmp = (unsigned long)p;
	if (p == NULL)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex(tmp, 0);
	return (count);
}

size_t	ft_putnbr(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
