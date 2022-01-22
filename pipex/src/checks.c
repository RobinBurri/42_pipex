/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:02:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/22 16:08:41 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// create a pipe for 
//input.txt >> grep "tes" | wc -l >> output.txt
	// if (argc != 5)
	// {
	// 	ft_putstr_fd("Usage: ./pipex [file1] [cmd1] [cmd2] [file2]", 2);
	// 	exit(1);
	// }

void	send_err(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	open_check_files(char *input, char *output, int *fdin, int *fdout)
{
	*fdin = open(input, O_RDONLY);
	*fdout = open(output, O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
	if (*fdin == -1 || *fdout == -1)
		send_err("OPEN ERROR");
	return (0);
}

void	close_check_files(int fdin, int fdout)
{
	int	c1;
	int	c2;

	c1 = close(fdin);
	c2 = close(fdout);
	if (c2 != 0 || c1 != 0)
		send_err("CLOSE ERROR");
}
