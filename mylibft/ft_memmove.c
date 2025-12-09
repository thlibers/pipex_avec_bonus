/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:57:28 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/16 18:16:14 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((char *)dest == NULL && (const char *)src == NULL)
		return (NULL);
	if ((const char *)src > (char *)dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((const char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

// int main()
// {
// 	char src[] = "salut";
// 	char dst[] = "ddddd";
// 	printf("%s", (char *)ft_memmove(dst, src, 3));
// 	return(0);
// }