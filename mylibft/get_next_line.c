/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:07:56 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/04 16:00:14 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_readnstock(char *stock, int fd)
{
	char	*storage;
	ssize_t	countbytes;

	countbytes = 1;
	storage = malloc(BUFFER_SIZE + 1);
	if (!storage)
		return (NULL);
	while (countbytes > 0 && !(ft_strchr_mod(stock, '\n')))
	{
		countbytes = read(fd, storage, BUFFER_SIZE);
		if (countbytes < 0)
		{
			free(storage);
			if (stock)
				free(stock);
			return (NULL);
		}
		storage[countbytes] = '\0';
		stock = ft_strjoin_mod(stock, storage);
	}
	return (free(storage), stock);
}

static char	*ft_extract_line(char *stock)
{
	char	*line;

	line = ft_strdup_mod(stock);
	if (!line)
		return (free(line), NULL);
	return (line);
}

static char	*ft_keep_it(char *stock)
{
	char	*storage;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (free(stock), NULL);
	storage = malloc((ft_strlen_mod(stock) - i) + 1);
	if (!storage)
		return (NULL);
	i++;
	while (stock[i])
		storage[j++] = stock[i++];
	storage[j] = 0;
	return (free(stock), storage);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_readnstock(stock, fd);
	if (!stock)
		return (NULL);
	line = ft_extract_line(stock);
	stock = ft_keep_it(stock);
	if (!stock)
		free(stock);
	return (line);
}
