/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:22:08 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/10 11:51:59 by nclavel          ###   ########.fr       */
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

// static void	child_process2(t_pipex *pipex)
// {
// 	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
// 		print_error("dup2 failed for pipe read");
// 	if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
// 		print_error("dup2 failed for outfile");
// 	close(pipex->infile_fd);
// 	close(pipex->outfile_fd);
// 	close(pipex->pipe_fd[0]);
// 	close(pipex->pipe_fd[1]);
// 	pipex->cmd2_path = find_command_path(pipex->cmd2_args[0], pipex->envp);
// 	if (!pipex->cmd2_path)
// 	{
// 		ft_putstr_fd("Error\npipex: ", STDERR_FILENO);
// 		ft_putstr_fd(pipex->cmd2_args[0], STDERR_FILENO);
// 		ft_putstr_fd(": command not found\n", STDERR_FILENO);
// 		cleanup_pipex(pipex);
// 		exit(127);
// 	}
// 	if (execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp) == -1)
// 	{
// 		print_error("execve failed");
// 		cleanup_pipex(pipex);
// 		exit(126);
// 	}
// 	free(pipex->cmd2_path);
// }

void	execute_pipex(t_pipex *pipex)
{
	pid_t	*pid;
	int		status;
	int		last_child_index;
	int		i;
	int		j;

	i = 2;
	j = 0;
	pid = NULL;
	pid = malloc(sizeof(int) * pipex->cmd_count);
	if (!pid)
		return ;
	last_child_index = find_last_child(pipex->argc);
	pipex->pipe_fd = ft_calloc(pipex->cmd_count, sizeof(int *));
	if (!pipex->pipe_fd)
		print_error("Allocation Pipe fd failed");
	while (i <= last_child_index)
	{
		printf ("last : %d | i : %d\n", last_child_index, i);
		pipex->pipe_fd[j] = malloc(sizeof(int) * 2);
		if (!pipex->pipe_fd[j])
			print_error("Pipe fd");
		if (pipe(pipex->pipe_fd[j]) == -1)
			print_error("Pipe creation failed");
		pid[j] = fork();
		if (pid[j] == -1)
			print_error("Fork creation failed");
		if (pid[j] == 0 && i == last_child_index)
		{
			child_process1(pipex);
			break ;
		}
		else if (pid[j] == 0)
		{
			child_process1(pipex);
			break ;
		}
		waitpid(pid[j], &status, 0);
		i++;
		j++;
	}
}

// boucler le child_process pour executer les n fonctions