/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:34:11 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/20 12:23:46 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)mem)[i] = '\0';
		i++;
	}
	return (mem);
}

// int main()
// {
// 	void *mem = ft_calloc(5, 1);
// 	printf("%s", (char *)mem);
// 	free (mem);
// 	return (0);
// }