/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:54 by rburri            #+#    #+#             */
/*   Updated: 2022/01/24 09:10:51 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	cmd1_child(char *cmd, int pipe_fd[], int fd[], char **envp)
{
	char	*path;
	char	**cmd_arg_arr;
	int exec_err;
	
	exec_err = 0;
	if (close(pipe_fd[0]) == -1)
		send_err("CLOSE PIPE ERR");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		send_err("DUP2 ERR");	
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		send_err("DUP2OUT ERR");
	if (close(pipe_fd[1]) == -1)
		send_err("CLOSE PIPE ERR");
	cmd_arg_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arg_arr[0], envp);
	printf("%s\n", path);
	if (path == NULL || execve(path, cmd_arg_arr, envp) == -1)
		exec_err = -1;
	ft_free_split(cmd_arg_arr);
	free(path);
	if (exec_err == -1)
		send_err("EXEC (1) ERR");
	return (0);
}

int	cmd2_child(char *cmd, int pipe_fd[], int fd[], char **envp)
{
	char	*path;
	char	**cmd_arg_arr;
	int exec_err;
	
	exec_err = 0;
	if (close(pipe_fd[1]) == -1)
		send_err("CLOSE PIPE ERR");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		send_err("DUP2 ERR");
	if (close(pipe_fd[0]) == -1)
		send_err("CLOSE PIPE ERR");	
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		send_err("DUP2OUT2 ERR");
	cmd_arg_arr = ft_split(cmd, ' ');
	printf("cmd_arr: %s\n", cmd_arg_arr[0]);
	path = find_path(cmd_arg_arr[0], envp);
	printf("%s\n", path);
	if (path == NULL || execve(path, cmd_arg_arr, envp) == -1)
		exec_err = -1;
	ft_free_split(cmd_arg_arr);
	free(path);
	if (exec_err == -1)
		send_err("EXEC (2) ERR");
	return (0);
}
