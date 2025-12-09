/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:59:47 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:35:25 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = (char)c;
	return (s);
}

// int main(void)
// {
// 	char str[] = "salut";
// 	ft_memset(str, '5', 2);
// 	printf("%s", str);
// 	return(0);
// }