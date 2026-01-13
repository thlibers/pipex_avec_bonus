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

char	*modded_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1 != NULL && s1[i])
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

char	*get_line(void)
{
	char	*buff;
	char	*line;
	int		bytes_read;

	bytes_read = 1;
	line = NULL;
	buff = ft_calloc(10 + 1, sizeof(char));
	if (!buff)
		return (NULL);
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
		if (!line)
			return (free(buff), NULL);
	}
	free(buff);
	return (line);
}

static int	heredoc_init(t_pipex *pipex)
{
	pipex->infile_fd = open(HEREDOC_F, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (pipex->infile_fd < 0)
	{
		cleanup_pipex(pipex);
		print_error("Failed to open/create/erase tmp file");
	}
	return (0);
}

int	here_doc(t_pipex *pipex)
{
	char	*line;

	line = NULL;
	heredoc_init(pipex);
	while (1)
	{
		if (line)
			free(line);
		write(1, "> ", 2);
		line = get_line();
		if (!line)
		{
			cleanup_pipex(pipex);
			print_error("Heredoc failed");
		}
		if (ft_strnstr(line, pipex->limiter, ft_strlen(line)))
			break ;
		ft_putstr_fd(line, pipex->infile_fd);
	}
	close(pipex->infile_fd);
	pipex->infile_fd = open("/tmp/pipex_heredoc.tmp", O_RDONLY);
	if (pipex->infile_fd < 0)
		print_error("Failed to reopen heredoc file for reading");
	free(line);
	return (0);
}
