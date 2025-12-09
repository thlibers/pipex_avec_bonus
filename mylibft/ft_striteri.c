/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:28:35 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/17 16:42:07 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void f(unsigned int n, char *c)
// {
// 	n = 0;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }

// int main()
// {
// 	char s[] = "salut";
// 	ft_striteri(s, f);
// 	printf ("%s", s);
// 	return (0);
// }