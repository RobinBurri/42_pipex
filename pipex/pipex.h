/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/01/22 17:14:04 by rburri           ###   ########.fr       */
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

int		open_check_files(char *input, char *output, int *fdin, int *fdout);
void	close_check_files(int fdin, int fdout);
void	send_err(char *s);
int		cmd1_child(char *s, int pipe_fd[], int fdin, char **envp);
int		cmd2_child(char *s, int pipe_fd[], int fdout, char **envp);
char	*find_path(char *cmd, char **envp);
#endif