/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:54 by rburri            #+#    #+#             */
/*   Updated: 2022/01/25 10:25:23 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	cmd1_child(t_pipex pipex, char ** argv, char **envp)
{
	if (close(pipex.pipe_fd[0]) == -1)
		send_err(CL_PIPE);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		send_err(DUP2_ERR );	
	if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
		send_err(DUP2_ERR );
	// if (close(pipex.pipe_fd[1]) == -1)
	// 	send_err(CL_PIPE);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_pipex(&pipex);
		send_err(CMD_ERR);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	cmd2_child(t_pipex pipex, char ** argv, char **envp)
{
	if (close(pipex.pipe_fd[1]) == -1)
		send_err(CL_PIPE);
	if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
		send_err(DUP2_ERR );
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		send_err(DUP2_ERR );
	// if (close(pipex.pipe_fd[0]) == -1)
	// 	send_err(CL_PIPE);	
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_pipex(&pipex);
		send_err(CMD_ERR);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
