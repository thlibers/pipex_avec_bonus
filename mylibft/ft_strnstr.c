/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:38:40 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 14:10:41 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			result = (char *)(big + i);
			while (big[i + j] == little[j] && i + j < len)
			{
				if (!little[j + 1])
					return (result);
				j++;
			}
			result = 0;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s\n", ft_strnstr("salut ca va ?", " ca", 15));
// 	printf("%s\n", ft_strnstr("salut ca va ?", "", 15));
// 	printf("%s\n", ft_strnstr("salut ca va ?", "fd", 15));
// 	printf("%s\n", ft_strnstr("salut ca va ?", "lu", 4));

// 	printf("%s\n", strnstr("salut ca va ?", " ca", 15));
// 	printf("%s\n", strnstr("salut ca va ?", "", 15));
// 	printf("%s\n", strnstr("salut ca va ?", "fd", 15));
// 	printf("%s\n", strnstr("salut ca va ?", "lu", 4));
// }