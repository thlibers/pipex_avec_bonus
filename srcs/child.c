/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:30:53 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/19 09:49:04 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void	one_command_only(t_pipex *pipex, int child_number)
{
	(void)child_number;
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		print_error("dup2 failed for pipe read");
	if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		print_error("dup2 failed for outfile");
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
}

static void	first_last_command(t_pipex *pipex, int child_number)
{
	if (child_number == 0)
	{
		if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
			print_error("dup2 failed for pipe read");
		if (dup2(pipex->pipe_fd[child_number][1], STDOUT_FILENO) == -1)
			print_error("dup2 failed for outfile");
		close(pipex->infile_fd);

	}
	else if (child_number == pipex->cmd_count - 1)
	{
		if (dup2(pipex->pipe_fd[child_number - 1][0], STDIN_FILENO) == -1)
			print_error("dup2 failed for pipe read");
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
			print_error("dup2 failed for outfile");
		close(pipex->outfile_fd);
		close(pipex->pipe_fd[child_number - 1][0]);
		close(pipex->pipe_fd[child_number - 1][1]);
	}
}

static void	setup_middle_command(t_pipex *pipex, int child_number)
{
	if (dup2(pipex->pipe_fd[child_number - 1][0], STDIN_FILENO) == -1)
		print_error("dup2 failed for pipe read");
	if (dup2(pipex->pipe_fd[child_number][1], STDOUT_FILENO) == -1)
		print_error("dup2 failed for pipe write");
	close(pipex->pipe_fd[child_number - 1][0]);
	close(pipex->pipe_fd[child_number - 1][1]);
	close(pipex->pipe_fd[child_number][0]);
	close(pipex->pipe_fd[child_number][1]);
}

static void	init_child(t_pipex *pipex, int child_number)
{
	int	i;

	i = 0;
	if ((child_number == 0 && child_number == pipex->cmd_count - 1))
		one_command_only(pipex, child_number);
	else if (child_number == 0
		|| child_number == pipex->cmd_count - 1)
		first_last_command(pipex, child_number);
	else
		setup_middle_command(pipex, child_number);
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (i != child_number - 1 && i != child_number)
		{
			close(pipex->pipe_fd[i][0]);
			close(pipex->pipe_fd[i][1]);
		}
		i++;
	}
}

void	child_process(t_pipex *pipex, int child_number)
{
	char	*cmd_path;

	init_child(pipex, child_number);
	cmd_path = find_command_path(pipex->cmd_args[child_number][0], pipex->envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error pipex: ", STDERR_FILENO);
		ft_putstr_fd(pipex->cmd_args[child_number][0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		cleanup_pipex(pipex);
		exit(127);
	}
	if (execve(cmd_path, pipex->cmd_args[child_number], pipex->envp) == -1)
	{
		print_error("execve failed");
		cleanup_pipex(pipex);
		exit(126);
	}
	free(cmd_path);
}
