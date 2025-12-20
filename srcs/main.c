/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:32 by thlibers          #+#    #+#             */
/*   Updated: 2025/12/15 11:38:11 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.envp = envp;
	if (!parse_args(argc, argv, &pipex))
	{
		cleanup_pipex(&pipex);
		print_error("Parsing failed");
	}
	if (pipex.limiter)
	{
		here_doc(&pipex);
	}
	execute_pipex(&pipex);
	cleanup_pipex(&pipex);
	return (0);
}
