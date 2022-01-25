/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:58:52 by rburri            #+#    #+#             */
/*   Updated: 2022/01/25 10:25:49 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	open_check_files(argc, argv, &pipex);
	if (pipe(pipex.pipe_fd) == -1)
		send_err(PIPE_CR);
	pipex.env_paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_paths, ':');	
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		send_err(FORK_ERR);
	if (pipex.pid1 == 0)
		cmd1_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		send_err(FORK_ERR);
	if (pipex.pid2 == 0)
		cmd1_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_main_pipex(&pipex);
	return (0);
}
