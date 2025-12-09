/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:22:08 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/09 18:17:02 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int find_last_child(int argc)
{
	int	index;

	index = 0;
	while(index < argc - 2)
	{
		index++;
	}
	return (index);
}

static void	child_process1(t_pipex *pipex)
{
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		print_error("dup2 failed for pipe read");
	if (dup2(pipex->pipe_fd[pipex->index][1], STDOUT_FILENO) == -1)
		print_error("dup2 failed for outfile");
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	close(pipex->pipe_fd[pipex->index][0]);
	close(pipex->pipe_fd[pipex->index][1]);
	pipex->cmd_paths[pipex->index] = find_command_path(pipex->cmd_args[pipex->index][0], pipex->envp);
	printf("CMD PATH  : %s\n", pipex->cmd_paths[pipex->index]);
	if (!pipex->cmd_paths[pipex->index])
	{
		ft_putstr_fd("Error\npipex: ", STDERR_FILENO);
		ft_putstr_fd(pipex->cmd_args[pipex->index][0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		cleanup_pipex(pipex);
		exit(127);
	}
	if (execve(pipex->cmd_paths[pipex->index], pipex->cmd_args[pipex->index], pipex->envp) == -1)
	{
		print_error("execve failed");
		cleanup_pipex(pipex);
		exit(126);
	}
	pipex->index++;
	free(pipex->cmd_paths[pipex->index]);
}

void	execute_pipex(t_pipex *pipex, int argc)
{
	pid_t	*pid;
	int		status;
	int		last_child_index;
	int		i;

	i = 0;
	pid = NULL;
	pid = malloc(sizeof(int) * pipex->cmd_count);
	if (!pid)
		return ;
	last_child_index = find_last_child(argc);
	pipex->pipe_fd = malloc(sizeof(int *) * last_child_index);
	if (!pipex->pipe_fd)
		print_error("Pipe fd");
	while (i < last_child_index)
	{
		pipex->pipe_fd[pipex->index] = malloc(sizeof(int) * 2);
		if (!pipex->pipe_fd[pipex->index])
			print_error("Pipe fd");
		if (pipe(pipex->pipe_fd[pipex->index]) == -1)
			print_error("pipe creation failed");
		// printf("%d\n", pid[i]);
		pid[i] = fork();
		if (pid[i] == -1)
			print_error("fork failed");
		if (pid[i] == 0)
		{
			printf("%d\n", pid[i]);
			child_process1(pipex);
		}
		i++;
		close(pipex->pipe_fd[pipex->index][0]);
		close(pipex->pipe_fd[pipex->index][1]);
		waitpid(pid[i], &status, 0);
	}
}

// boucler le child_process pour executer les n fonctions