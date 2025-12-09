/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:16:32 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 14:03:00 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	mapi = malloc(ft_strlen(s) + 1);
	if (!mapi)
		return (NULL);
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = 0;
	return (mapi);
}

// char f(unsigned int n, char c)
// {
// 	n = 0;
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

// int main()
// {
// 	char *mapi;
// 	char s[] = "salut";
// 	mapi = ft_strmapi(s, f);
// 	printf ("%s", mapi);
// 	free(mapi);
// 	return (0);
// }