/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/12 08:58:49 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HEREDOC_F "/tmp/pipex_heredoc.tmp"

# include "../mylibft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_pipex
{
	char	***cmd_args;
	char	**argv;
	char	**envp;
	char	*limiter;
	int		(*pipe_fd)[2];
	int		infile_fd;
	int		outfile_fd;
	int		argc;
	int		cmd_count;
	int		index;
	int		heredoc;
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
void		child_process(t_pipex *pipex, int cmd_count);
int			here_doc(t_pipex *pipex);

// utils.c
void		cleanup_pipex(t_pipex *pipex);
void		free_array(char **array);
void		print_error(char *message);

#endif
