/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:58:52 by rburri            #+#    #+#             */
/*   Updated: 2022/01/22 17:14:34 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;
	int	pipe_fd[2];
	int	process_id[2];

	open_check_files(argv[1], argv[2], &fdin, &fdout);
	if (pipe(pipe_fd) == -1)
		send_err("PIPE CREATION ERR");
	process_id[0] = fork();
	if (process_id[0] < 0)
		send_err("FORK ERR");
	if (process_id[0] == 0)
		cmd1_child(argv[1], pipe_fd, fdin, envp);
	process_id[1] = fork();
	if (process_id[1] < 0)
		send_err("FORK ERR");
	if (process_id[1] == 0)
		cmd2_child(argv[2], pipe_fd, fdout, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	close_check_files(fdin, fdout);
	return (0);
}
