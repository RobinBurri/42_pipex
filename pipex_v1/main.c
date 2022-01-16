/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:41:11 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/17 18:38:51 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**set_cmd(char *arg)
{
	int		env_count;
	int		list_count;
	char	**cmd_splitted_list;
	char	**cmd_arg_list;

	env_count = 0;
	cmd_splitted_list = cmd_split(arg, &env_count, &list_count);
	cmd_arg_list = get_args(cmd_splitted_list, env_count, list_count);
	free(cmd_splitted_list);
	return (cmd_arg_list);
}

/*
char  **set_env(char *arg)
{
	int		env_count;
	int		list_count;
	char	**cmd_splitted_list;
	char	**cmd_env_list;
	
	env_count = 0;
	cmd_splitted_list = cmd_split(arg, &env_count, &list_count);
	cmd_env_list = get_envs(cmd_splitted_list, env_count);

	// in a dedicate ft in find_path
	// PARSE cmd_env_list
	// to get env with PATH=...:...
	
	free(cmd_splitted_list);
	return(cmd_env_list);
}
*/

static void	execution_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(strerror(errno), 2);
}

int	child_process(char *cmd1, char **envp, int fd_infile, int *pipefd)
{
	char	**cmd_arg_list;
	char	*path;
	int		cmd_error;

	if (dup2(fd_infile, STDIN_FILENO) == -1)
		exit (GENERAL_ERROR);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit (GENERAL_ERROR);
	if (close(pipefd[0]) == -1)
		exit (GENERAL_ERROR);
	cmd_error = 0;
	cmd_arg_list = set_cmd(cmd1);
	path = find_path(cmd_arg_list[0], envp);
	if (path == NULL || execve(path, cmd_arg_list, envp) == -1)
		cmd_error = 1;
	ft_free_arr(cmd_arg_list);
	free(path);
	if (cmd_error)
	{
		execution_error("Error in cmd1 execution\n");
		exit (PATH_ERROR);
	}
	return (0);
}

int	parent_process(char *cmd2, char **envp, int fd_outfile, int *pipefd)
{
	char	**cmd_arg_list;
	char	*path;
	int		cmd_error;

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		exit(GENERAL_ERROR);
	if (close(pipefd[1]) == -1)
		exit(GENERAL_ERROR);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		exit(GENERAL_ERROR);
	cmd_error = 0;
	cmd_arg_list = set_cmd(cmd2);
	path = find_path(cmd_arg_list[0], envp);
	if (path == NULL || execve(path, cmd_arg_list, envp) == -1)
		cmd_error = 1;
	ft_free_arr(cmd_arg_list);
	free(path);
	if (cmd_error)
	{
		execution_error("Error in cmd2 execution\n");
		exit(PATH_ERROR);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_infile;
	int		fd_outfile;
	int		pipefd[2];
	pid_t	child;

	errno = 0;
	fd_infile = 0;
	fd_outfile = 0;
	files_check(argc, argv[1], argv[4]);
	files_open(&fd_infile, &fd_outfile, argv[1], argv[4]);
	if (pipe(pipefd) == -1)
		exit(GENERAL_ERROR);
	child = fork();
	if (child < 0)
		exit(GENERAL_ERROR);
	if (child == 0)
		child_process(argv[2], envp, fd_infile, pipefd);
	else
	{
		parent_process(argv[3], envp, fd_outfile, pipefd);
		wait(NULL);
	}
	return (0);
}
