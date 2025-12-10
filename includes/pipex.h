/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/10 16:42:35 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../mylibft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	***cmd_args;
	char	**argv;
	char	**envp;
	int		(*pipe_fd)[2];
	int		infile_fd;
	int		outfile_fd;
	int		argc;
	int		cmd_count;
	int		index;
}			t_pipex;

// parsing.c
int			open_infile(char *filename);
int			open_outfile(char *filename);
int			parse_args(int argc, char **argv, t_pipex *pipex);
char		**parse_command(char *cmd_str);

// commands.c
char		*find_command_path(char *cmd, char **envp);

// Execution.c
void		execute_pipex(t_pipex *pipex);

// utils.c
void		cleanup_pipex(t_pipex *pipex);
void		free_array(char **array);
void		print_error(char *message);

#endif