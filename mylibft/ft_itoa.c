/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:58:44 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:15:13 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*alpha;
	int		count;
	long	nb;

	nb = (long)n;
	count = nbrlen(nb);
	alpha = malloc(count + 1);
	if (alpha == NULL)
		return (NULL);
	if (nb < 0)
	{
		alpha[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		alpha[0] = '0';
	alpha[count] = '\0';
	while (nb > 0)
	{
		count--;
		alpha[count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (alpha);
}

// int main ()
// {
// 	printf("%s\n", ft_itoa(12546));
// 	printf("%s\n", ft_itoa(-12546));
// 	printf("%s\n", ft_itoa(-1));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return(0);
// }