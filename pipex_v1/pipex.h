/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:47:54 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/17 18:41:13 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# include "libft/libft.h"

# define GENERAL_ERROR 1
# define PERMISSION_ERROR 126
# define PATH_ERROR 127

int		files_check(int argc, char *infile, char *outfile);
int		files_open(int *fd1, int *fd2, char *infile, char *outfile);

int		check_cmd_syntax(char *cmd, int count, int *env_count);
char	**cmd_split(char *cmd, int *env_count, int *list_count);
char	**get_args(char **cmd_splitted_list, int env_count, int list_count);
// char	**get_envs(char **cmd_splitted_list, int env_count);

char	*find_path(char *cmd, char **envp);

#endif
