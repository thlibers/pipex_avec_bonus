/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:21:56 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/16 18:27:11 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
		j++;
	i = j;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

// int main (void)
// {
// 	printf("%s\n", ft_strrchr("sTalTuTation", 84));
// 	printf("%s\n", strrchr("sTalTuTation", 84));
// 	return(0);
// }