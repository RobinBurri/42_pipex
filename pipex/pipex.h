/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/01/25 10:25:12 by rburri           ###   ########.fr       */
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
# define GEN_ERR 1
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
void	cmd1_child(t_pipex pipex, char ** argv, char **envp);
void	cmd2_child(t_pipex pipex, char ** argv, char **envp);
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
void	send_err(char *s);
void	free_main_pipex(t_pipex *pipex);
void	free_child_pipex(t_pipex *pipex);

#endif