/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:21:56 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/20 12:26:17 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// int main (void)
// {
// 	printf("%s\n", ft_strchr("saluTation", 0));
// 	printf("%s\n", strchr("saluTation", 0));
// 	return(0);
// }