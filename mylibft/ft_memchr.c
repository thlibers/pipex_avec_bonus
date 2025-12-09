/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:42:07 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:41:12 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;

	result = (unsigned char *)s;
	while (n > 0)
	{
		if (*result == (unsigned char)c)
			return ((void *)result);
		result++;
		n--;
	}
	if (!c && n > 0)
		return ((void *)&result[ft_strlen((char *) s)]);
	return (NULL);
}

// int main (void)
// {
// 	printf("%s\n", (char*)ft_memchr("saltutTation", 84, 6));
// 	printf("%s\n", (char*)memchr("saltutTation", 84, 6));
// 	return(0);
// }