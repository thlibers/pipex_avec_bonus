/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:32 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/10 11:34:29 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	// if (ac != 5)
	// 	print_error("too many/few arguments");
	if (parse_args(argc, argv, &pipex) == -1)
	{
		cleanup_pipex(&pipex);
		print_error("Parsing failed");
	}
	pipex.envp = envp;
	execute_pipex(&pipex);
	cleanup_pipex(&pipex);
	return (0);
}
