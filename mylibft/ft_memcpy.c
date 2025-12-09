/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:41:25 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:37:11 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!(char *)dest && !(char *)src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char dest[] = "salut";
// 	char src[] = "ddddd";
// 	ft_memcpy(dest, src, 2);
// 	printf("%s", dest);
// 	return(0);
// }