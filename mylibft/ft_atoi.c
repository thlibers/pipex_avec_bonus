/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:50:58 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/21 13:38:13 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("123265"));
// 	printf("%d\n", atoi("123265"));

// 	printf("%d\n", ft_atoi("-1235"));
// 	printf("%d\n", atoi("-1235"));

// 	printf("%d\n", ft_atoi("   -1789"));
// 	printf("%d\n", atoi("   -1789"));
// }