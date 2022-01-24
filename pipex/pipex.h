/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/01/24 08:39:18 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

# include <stdio.h>

// ERRORS MESSAGES
# define GEN_ERR 1

int		open_check_files(int argc, char *input, char *output, int *fd);
void	close_check_files(int *fd);
void	send_err(char *s);
int		cmd1_child(char *s, int pipe_fd[], int fd[], char **envp);
int		cmd2_child(char *s, int pipe_fd[], int fd[], char **envp);
char	*find_path(char *cmd, char **envp);
#endif