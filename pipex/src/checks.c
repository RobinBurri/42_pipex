/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:02:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/24 08:18:08 by rburri           ###   ########.fr       */
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

int	open_check_files(int argc, char *input, char *output, int *fd)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex [file1] [cmd1] [cmd2] [file2]", 2);
		exit(1);
	}
	fd[0] = open(input, O_RDONLY);
	fd[1] = open(output, O_WRONLY);
	if (fd[0] == -1 || fd[1] == -1)
		send_err("OPEN ERROR");
	return (0);
}

void	close_check_files(int *fd)
{
	int	c1;
	int	c2;

	c1 = close(fd[0]);
	c2 = close(fd[1]);
	if (c2 != 0 || c1 != 0)
		send_err("CLOSE ERROR");
}
