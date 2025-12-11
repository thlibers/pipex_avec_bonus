/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:18:25 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/11 13:33:33 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_infile(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(filename);
	return (fd);
}

int	open_outfile(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error(filename);
	return (fd);
}

char	**parse_command(char *cmd_str)
{
	char	**arguments;
	char	*trimmed;

	if (!cmd_str || !*cmd_str)
		return (NULL);
	trimmed = ft_strtrim(cmd_str, " \t\n");
	if (!trimmed)
		return (NULL);
	arguments = ft_split(trimmed, ' ');
	free(trimmed);
	if (!arguments)
		return (NULL);
	if (!arguments[0] || !arguments[0][0])
	{
		free_array(arguments);
		return (NULL);
	}
	return (arguments);
}

static int	init_parsing(t_pipex *pipex, int argc, char **argv)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->cmd_count = argc - 3;
	pipex->infile_fd = open_infile(pipex->argv[1]);
	if (pipex->infile_fd == 0)
		return (0);
	pipex->outfile_fd = open_outfile(argv[argc - 1]);
	if (pipex->outfile_fd == 0)
		return (0);
	pipex->cmd_args = malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!pipex->cmd_args)
		return (0);
	return (1);
}

int	parse_args(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!init_parsing(pipex, argc, argv))
		return (0);
	while (i < pipex->cmd_count)
	{
		pipex->cmd_args[i] = parse_command(argv[i + 2]);
		if (!pipex->cmd_args[i])
		{
			close(pipex->infile_fd);
			close(pipex->outfile_fd);
			return (0);
		}
		i++;
	}
	pipex->cmd_args[i] = NULL;
	return (1);
}
