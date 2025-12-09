/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:08:25 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/04 16:00:07 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_mod(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy_mod(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strchr_mod(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup_mod(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = NULL;
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	dup = malloc(i + 2);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		dup[i++] = '\n';
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s2)
		return (s1);
	join = malloc(ft_strlen_mod(s1) + ft_strlen_mod(s2) + 1);
	if (join == NULL)
		return (NULL);
	j = 0;
	i = ft_strlen_mod(s1);
	ft_strcpy_mod(join, s1);
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join[i + j] = '\0', free(s1), join);
}
