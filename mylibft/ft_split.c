/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:26:53 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/04 14:04:28 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == sep)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != sep)
			i++;
		count++;
		while (s[i] && s[i] == sep)
			i++;
	}
	return (count);
}

static char	*word_dup(const char *s, char sep)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != sep)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != sep)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	free_tab(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		tab[j] = word_dup(&(s[i]), c);
		if (!tab[j])
			return (free_tab(tab), NULL);
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

// int main()
// {
// 	size_t j;
// 	j = 0;
// 	char str[] = "salut/f/wooooow/";
// 	char sep = '/';
// 	char **s;
// 	s = ft_split(str, sep);
// 	while (s[j])
// 	{
// 		printf ("%s\n", s[j]);
// 		j++;
// 	}
// 	free_tab(s);
// 	return(0);
// }