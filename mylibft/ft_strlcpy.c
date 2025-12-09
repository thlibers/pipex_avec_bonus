/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:21:56 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 12:01:38 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < (size -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}

// int main(void)
// {
// 	char dest[] = "saluthhh";
// 	char src[] = "ddddd";
// 	printf("%zu", ft_strlcpy(dest, src, 15));
// 	return(0);
// }