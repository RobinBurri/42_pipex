/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:02:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/25 10:28:44 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	send_err(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	open_check_files(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex [file1] [cmd1] [cmd2] [file2]", 1);
		exit(1);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->pipe_fd[0] == -1)
		send_err(OPEN_IN);
	if (pipex->pipe_fd[1] == -1)
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
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}