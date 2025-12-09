/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:16:16 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/04 15:59:49 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chooseformat(int type, va_list param)
{
	if (type == 'c')
		return (ft_putchar(va_arg(param, int)));
	if (type == 's')
		return (ft_putstr(va_arg(param, char *)));
	if (type == 'p')
		return (ft_putptr(va_arg(param, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(param, int)));
	if (type == 'u')
		return (ft_putunbr(va_arg(param, unsigned int)));
	if (type == 'x')
		return (ft_puthex(va_arg(param, unsigned int), 0));
	if (type == 'X')
		return (ft_puthex(va_arg(param, unsigned int), 1));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			param;
	unsigned int	storage;
	int				i;

	i = 0;
	storage = 0;
	if (!format)
		return (0);
	va_start(param, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			storage += ft_chooseformat(format[i + 1], param);
			i++;
		}
		else
			storage += ft_putchar(format[i]);
		i++;
	}
	va_end(param);
	return (storage);
}

// int main(void)
// {
// 	char *str = NULL;
// 	ft_printf("%s\n", str);
// 	// printf("%s", str);

// 	// ft_printf("Character: %c\n", 'A');
// 	// printf("Character: %c\n", 'A');
// 	// ft_printf("String: %s\n", "j'ai faim!");
// 	// printf("String: %s\n", "j'ai faim!");
// 	// ft_printf("Pointer: %p\n", &main);
// 	// printf("Pointer: %p\n", &main);
// 	// ft_printf("Integer: %d\n", 42);
// 	// printf("Integer: %d\n", 42);
// 	// ft_printf("Unsigned: %u\n", 12345);
// 	// printf("Unsigned: %u\n", 12345);
// 	// ft_printf("Hex low: %x\n", -255);
// 	// printf("Hex low: %x\n", -255);
// 	// ft_printf("Hex up: %X\n", 255);
// 	// printf("Hex up: %X\n", 255);
// 	// ft_printf("Pct: %%\n");
// 	// printf("Pct: %%\n");
// 	return (0);
// }