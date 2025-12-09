/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:22:01 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 14:11:32 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ext;
	size_t	i;

	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ext = malloc(sizeof(char) * len + 1);
	if (!ext)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ext[i] = s[start + i];
		i++;
	}
	ext[i] = 0;
	return (ext);
}

// int main()
// {
// 	char s1[] = "sjfCa  tuee  d  !!!";
// 	char *ext = ft_substr(s1, 5, 15);
// 	printf("%s", ext);
// 	free (ext);
// 	return(0);
// }