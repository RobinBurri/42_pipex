/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/01/27 06:48:15 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
//for close, pipe, dup2
# include <fcntl.h>
//for open
# include <stdlib.h>
// for malloc, free, exit
# include <sys/wait.h>
// for waitpid
# include <errno.h>
// for errno
# include <stdio.h>
// for perror
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	*env_paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}				t_pipex;

// ERRORS MESSAGES
# define USG_ERR "Usage: ./pipex [file1] [cmd1] [cmd2] [file2]"
# define OPEN_IN "OPEN INPUT ERROR"
# define OPEN_OUT "OPEN OUTPUT ERROR"
# define PIPE_CR "PIPE CREATION ERROR"
# define FORK_ERR "FORK ERROR"
# define CL_PIPE	"CLOSE PIPE ERR"
# define DUP2_ERR "DUP2 ERR"
# define CMD_ERR "CMD ERROR"

void	open_check_files(int argc, char **argv, t_pipex *pipex);
void	close_check_files(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	cmd1_child(t_pipex pipex, char **argv, char **envp);
void	cmd2_child(t_pipex pipex, char **argv, char **envp);
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
void	send_err(char *s);
void	free_main_pipex(t_pipex *pipex);
void	free_cmd_pipex(t_pipex *pipex);

#endif