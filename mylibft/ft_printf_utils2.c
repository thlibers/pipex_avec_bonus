/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:16:04 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/04 15:59:41 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putunbr(unsigned long n)
{
	size_t	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

size_t	ft_puthex(unsigned long n, int b)
{
	char	*base;
	size_t	count;

	if (b == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, b);
	count += ft_putchar(base[n % 16]);
	return (count);
}
