/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:02:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/25 10:36:43 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_check_files(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		send_err(USG_ERR);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->infile == -1)
		send_err(OPEN_IN);
	if (pipex->outfile == -1)
		send_err(OPEN_OUT);
}

void	close_check_files(t_pipex *pipex)
{
	int	c1;
	int	c2;

	c1 = close(pipex->infile);
	c2 = close(pipex->outfile);
	if (c2 != 0 || c1 != 0)
		send_err("CLOSE ERROR");
}

void	close_pipes(t_pipex *pipex)
{
	int	c1;
	int	c2;

	c1 = close(pipex->pipe_fd[0]);
	c2 = close(pipex->pipe_fd[1]);
	if (c2 != 0 || c1 != 0)
		send_err("CLOSE ERROR");
}
