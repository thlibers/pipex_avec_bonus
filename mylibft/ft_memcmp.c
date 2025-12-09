/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:10:15 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:39:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// int main()
// {
// 	printf("%d\n", ft_memcmp("sablut", "salut", 3));
// 	printf("%d\n", memcmp("sablut", "salut", 3));
// 	printf("%d\n", ft_memcmp("sa", "salut", 3));
// 	printf("%d\n", memcmp("sa", "salut", 3));
// 	printf("%d\n", ft_memcmp("sablut", "sa", 3));
// 	printf("%d\n", memcmp("sablut", "sa", 3));
// }