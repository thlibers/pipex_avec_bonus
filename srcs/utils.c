/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:22:25 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/11 12:46:55 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_argsnpath(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		if (pipex->cmd_args[i])
		{
			free_array(pipex->cmd_args[i]);
			pipex->cmd_args[i] = NULL;
		}
		i++;
	}
	if (pipex->cmd_args)
		free(pipex->cmd_args);
}

void	cleanup_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex)
		return ;
	if (pipex->infile_fd > 2)
		(close(pipex->infile_fd), pipex->infile_fd = -1);
	if (pipex->outfile_fd > 2)
		(close(pipex->outfile_fd), pipex->outfile_fd = -1);
	while (i < pipex->cmd_count)
	{
		if (pipex->pipe_fd[i][0] > 2)
			(close(pipex->pipe_fd[i][0]), pipex->pipe_fd[i][0] = -1);
		if (pipex->pipe_fd[i][1] > 2)
			(close(pipex->pipe_fd[i][1]), pipex->pipe_fd[i][1] = -1);
		i++;
	}
	if (pipex->pipe_fd)
		free(pipex->pipe_fd);
	free_argsnpath(pipex);
}
