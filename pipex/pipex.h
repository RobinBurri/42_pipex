/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/01/22 14:35:40 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "libft/libft.h"

#include <stdio.h>


int		open_check_files(char *input, char *output, int *fdin, int *fdout, int argc);
void	close_check_files(int fdin, int fdout);
#endif