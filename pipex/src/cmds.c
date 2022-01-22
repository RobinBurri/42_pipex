/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:54 by rburri            #+#    #+#             */
/*   Updated: 2022/01/22 17:25:24 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	cmd1_child(char *cmd, int pipe_fd[], int fdin, char **envp)
{
	char	*path;
	char	**cmd_arg_arr;
	
	if (close(pipe_fd[0]) == -1)
		send_err("CLOSE PIPE ERR");
	if (dup2(fdin, STDIN_FILENO) == -1)
		send_err("DUP2 ERR");
	if (dup2(pipe_fd[1], STDOUT_FILENO))
		send_err("DUP2 ERR");
	if (close(pipe_fd[1]))
		send_err("CLOSE PIPE ERR");
	cmd_arg_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arg_arr[0], envp);
	execlp("grep", "grep", " tes ", NULL);
	return (0);
}

int	cmd2_child(char *cmd, int pipe_fd[], int fdout, char **envp)
{
	char	*path;
	char	**cmd_arg_arr;
	
	if (close(pipe_fd[1]) == -1)
		send_err("CLOSE PIPE ERR");
	if (dup2(pipe_fd[0], STDIN_FILENO))
		send_err("DUP2 ERR");
	if (close(pipe_fd[0]) == -1)
		send_err("CLOSE PIPE ERR");
	if (dup2(fdout, STDOUT_FILENO))
		send_err("DUP2 ERR");
	cmd_arg_arr = split_cmd(cmd);
	path = find_path(cmd_arg_arr[0], envp);
	execlp("wc", "wc", NULL);
	return (0);
}
