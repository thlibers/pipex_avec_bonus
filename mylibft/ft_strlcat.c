/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:55:06 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 13:58:12 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = ft_strlen(dst);
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (ft_strlen(src) + size);
	while (src [i] != '\0' && i < (size - dlen - 1))
		dst[j++] = src[i++];
	dst[j] = 0;
	return (dlen + slen);
}

// int main(void)
// {
// 	char dest[] = "salutd";
// 	char src[] = "ddddd";
// 	printf("%zu\n", ft_strlcat(dest, src, 80));
// 	char dest1[] = "salutd";
// 	char src1[] = "ddddd";
// 	printf("%zu\n", strlcat(dest1, src1, 80));
// 	return(0);
// }