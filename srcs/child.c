/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:30:53 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/11 13:39:51 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void	first_last_command(t_pipex *pipex, int cmd_count)
{
	if (cmd_count == 0)
	{
		if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
			print_error("dup2 failed for pipe read");
		if (dup2(pipex->pipe_fd[cmd_count][1], STDOUT_FILENO) == -1)
			print_error("dup2 failed for outfile");
		close(pipex->infile_fd);
		close(pipex->pipe_fd[cmd_count][1]);
		close(pipex->pipe_fd[cmd_count][0]);
	}
	else if (cmd_count == pipex->cmd_count - 1)
	{
		if (dup2(pipex->pipe_fd[cmd_count - 1][0], STDIN_FILENO) == -1)
			print_error("dup2 failed for pipe read");
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
			print_error("dup2 failed for outfile");
		close(pipex->outfile_fd);
		close(pipex->pipe_fd[cmd_count - 1][0]);
		close(pipex->pipe_fd[cmd_count - 1][1]);
	}
}

static void	setup_middle_command(t_pipex *pipex, int cmd_count)
{
	if (dup2(pipex->pipe_fd[cmd_count - 1][0], STDIN_FILENO) == -1)
		print_error("dup2 failed for pipe read");
	if (dup2(pipex->pipe_fd[cmd_count][1], STDOUT_FILENO) == -1)
		print_error("dup2 failed for pipe write");
	close(pipex->pipe_fd[cmd_count - 1][0]);
	close(pipex->pipe_fd[cmd_count - 1][1]);
	close(pipex->pipe_fd[cmd_count][0]);
	close(pipex->pipe_fd[cmd_count][1]);
}

static void	init_child(t_pipex *pipex, int cmd_count)
{
	int	i;

	i = 0;
	if (cmd_count == 0 || cmd_count == pipex->cmd_count - 1)
		first_last_command(pipex, cmd_count);
	else
		setup_middle_command(pipex, cmd_count);
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (i != cmd_count - 1 && i != cmd_count)
		{
			close(pipex->pipe_fd[i][0]);
			close(pipex->pipe_fd[i][1]);
		}
		i++;
	}
}

void	child_process(t_pipex *pipex, int cmd_count)
{
	char	*cmd_path;
	int		i;

	i = 0;
	init_child(pipex, cmd_count);
	cmd_path = find_command_path(pipex->cmd_args[cmd_count][0], pipex->envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error pipex: ", STDERR_FILENO);
		ft_putstr_fd(pipex->cmd_args[cmd_count][0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		cleanup_pipex(pipex);
		exit(127);
	}
	if (execve(cmd_path, pipex->cmd_args[cmd_count], pipex->envp) == -1)
	{
		print_error("execve failed");
		cleanup_pipex(pipex);
		exit(126);
	}
	free(cmd_path);
}
