/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:22:08 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/10 17:51:50 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static void	child_process(t_pipex *pipex, int cmd_count)
{
	char *cmd_path;
	int	i;
	
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
	cmd_path = find_command_path(pipex->cmd_args[cmd_count][0], pipex->envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error\npipex: ", STDERR_FILENO);
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
	printf("123\n");
	free(cmd_path);
}

void	execute_pipex(t_pipex *pipex)
{
	pid_t	*pid;
	int		status;
	int		i;

	pid = NULL;
	pid = malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pid)
		print_error("Allocation pid array failed");
	pipex->pipe_fd = ft_calloc(pipex->cmd_count, sizeof(int *));
	if (!pipex->pipe_fd)
		print_error("Allocation Pipe_fd array failed");
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(pipex->pipe_fd[i]) == -1)
			print_error("Pipe creation failed");
		i++;
	}
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
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		close(pipex->pipe_fd[i][0]);
		close(pipex->pipe_fd[i][1]);
		i++;
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	free(pid);
}
