/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:00:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/19 09:54:56 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char  *modded_join(char *s1, char *s2)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	return (str[i + j] = '\0', str);
}

char  *get_line()
{
	char  *buff;
	char  *line;
	int	  bytes_read;

	bytes_read = 1;
	buff = malloc(sizeof(char) * (10 + 1));
	line = malloc(sizeof(char) * (1));
	while (!ft_strchr(buff, '\n') && bytes_read > 0)
	{
		bytes_read = read(0, buff, 10);
		if (bytes_read < 0)
		{
			if (buff)
				free(buff);
		}
		buff[bytes_read] = '\0';
		line = modded_join(line, buff);
	}
	return (line);
}

int	here_doc(t_pipex *pipex)
{
	char  *line = "";
	int	  bytes_read;

	printf("%s\n", pipex->limiter);
	pipex->infile_fd = open("/tmp/pipex_heredoc.tmp", O_RDWR | O_CREAT, 0777);
	if (!pipex->infile_fd)
		return 1;
	while (!ft_strnstr(line, pipex->limiter, ft_strlen(line)) && 1)
	{
//		if (line)
//			free(line);
		write(1, "> ", 2);
		line = get_line();
		bytes_read = write(pipex->infile_fd, &line, ft_strlen(line));
		if (bytes_read <= 0)
			return 0;

	}
	return (0);
}
