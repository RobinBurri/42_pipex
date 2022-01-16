/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:43:04 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/17 18:39:03 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_files_open_error_msg(char *msg, char *file)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(")\n", 2);
}

static void	print_files_check_error_msg(char *msg, char *file)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd('\n', 2);
}

int	files_open(int *fd1, int *fd2, char *infile, char *outfile)
{
	*fd1 = open(infile, O_RDONLY);
	if (*fd1 == -1)
	{
		print_files_open_error_msg(strerror(errno), infile);
		exit(GENERAL_ERROR);
	}
	*fd2 = open(outfile, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (*fd2 == -1)
	{
		print_files_open_error_msg(strerror(errno), outfile);
		exit(GENERAL_ERROR);
	}
	return (0);
}

int	files_check(int argc, char *infile, char *outfile)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
		exit(GENERAL_ERROR);
	}
	if (access(infile, R_OK) == -1)
	{
		print_files_check_error_msg(strerror(errno), infile);
		exit(PERMISSION_ERROR);
	}
	if (access(outfile, F_OK) == 0)
	{
		if (access(outfile, W_OK) == -1)
		{
			print_files_check_error_msg(strerror(errno), outfile);
			exit(PERMISSION_ERROR);
		}
	}
	return (0);
}
