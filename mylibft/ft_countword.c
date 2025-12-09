/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:58:08 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/19 17:40:04 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countword(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		count++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (count);
}
