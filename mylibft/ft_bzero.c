/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:33:51 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 11:35:43 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

// int main(void)
// {
// 	char str[] = "salut";
// 	ft_bzero(str, 2);
// 	printf("%s", str);
// 	return(0);
// }