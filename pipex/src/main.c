/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:58:52 by rburri            #+#    #+#             */
/*   Updated: 2022/01/24 08:39:47 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//file input = fd[0]
//file output = fd[1]

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2] = {0};
	int	pipe_fd[2];
	int	process_id[2];

	open_check_files(argc, argv[1], argv[4], fd);
	if (pipe(pipe_fd) == -1)
		send_err("PIPE CREATION ERR");
	printf("fd[0]: %d, fd[1]: %d\n", fd[0], fd[1]);
	printf("pipe_fd[0]: %d, pipe_fd[1]: %d\n", pipe_fd[0], pipe_fd[1]);
	process_id[0] = fork();
	if (process_id[0] < 0)
		send_err("FORK ERR");
	if (process_id[0] == 0)
		cmd1_child(argv[1], pipe_fd, fd, envp);
	process_id[1] = fork();
	if (process_id[1] < 0)
		send_err("FORK ERR");
	if (process_id[1] == 0)
		cmd2_child(argv[2], pipe_fd, fd, envp);
	wait(NULL);
	wait(NULL);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close_check_files(fd);
	return (0);
}
