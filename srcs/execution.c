/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:22:08 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/12 08:38:57 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipes_creation(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(pipex->pipe_fd[i]) == -1)
			print_error("Pipe creation failed");
		i++;
	}
}

static void	pipes_close(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		close(pipex->pipe_fd[i][0]);
		close(pipex->pipe_fd[i][1]);
		i++;
	}
}

static void	children_creation(t_pipex *pipex, pid_t *pid)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			print_error("Fork creation failed");
		if (pid[i] == 0)
			child_process(pipex, i);
		i++;
	}
}

void	execute_pipex(t_pipex *pipex)
{
	pid_t	*pid;
	int		status;
	int		i;

	i = 0;
	pid = NULL;
	pid = malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pid)
		print_error("Allocation pid array failed");
	pipex->pipe_fd = ft_calloc(pipex->cmd_count, sizeof(int *));
	if (!pipex->pipe_fd)
		print_error("Allocation Pipe_fd array failed");
	pipes_creation(pipex);
	children_creation(pipex, pid);
	pipes_close(pipex);
	while (i < pipex->cmd_count)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	free(pid);
}
